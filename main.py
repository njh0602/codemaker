from jinja2 import Template
import os
import csv
import re

def generate_type_from_csv(output_folder, folder_path):
    enum_datas = []
    csv_files = [f for f in os.listdir(folder_path) if f.endswith('.csv')]
    for file_name in csv_files:
        with open(os.path.join(folder_path, file_name), newline='') as csvfile:
            csv_reader = csv.reader(csvfile)
            data = list(csv_reader)
            enum_datas.append({
                'file_name': file_name, 
                'enum_name': os.path.splitext(file_name)[0],
                'enum_values' : [enum_value[0] for enum_value in data]
            })

    with open('./template/Types.tt', 'r') as file:
        template_content = file.read()

    template = Template(template_content)
    cpp_code = template.render(enums=enum_datas)

    with open(os.path.join(output_folder, f"Types.hpp"), 'w') as single_header_file:
        single_header_file.write(cpp_code)

def generate_table_from_csv(output_folder, folder_path):
    generate_path = os.path.join(output_folder, f"Tables.hpp")

    header_code = """// This file has been generated automatically. Don't modify it.

#ifndef __TABLES_H__
#define __TABLES_H__

#include <vector>
#include <array>
#include <unordered_map>
#include <string>
#include <sstream>

#include "Types.hpp"
#include "csv.h"

template <typename T>
static std::vector<T> split(const std::string& s, char delimiter = ',') {
    std::vector<T> tokens;
    std::istringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        std::istringstream converter(token);
        T value;
        if constexpr (std::is_enum_v<T>) {
            value = static_cast<T>(std::stoi(token));
        }
        else {
            converter >> value;
        }
        tokens.push_back(value);
    }
    return tokens;
}\n
"""

    class_names = []
    csv_files = [f for f in os.listdir(folder_path) if f.endswith('.csv')]
    for file_name in csv_files:
        file_path = os.path.join(folder_path, file_name)
        class_name = os.path.splitext(file_name)[0]
        class_names.append(class_name)

        with open(file_path, newline='') as csvfile:
            csv_reader = csv.reader(csvfile)
            data = list(csv_reader)
            header_code += generate_table_class(data, file_name, class_name)
            
        header_code += '\n'

    header_code += 'class TblLoader {\n'
    header_code += 'public:\n'
    header_code += '    static bool initialize(const std::string& folderPath) {\n'
    for class_name in class_names:
        header_code += f'        initialize<{class_name}>(folderPath + "/{class_name}.csv");\n'
    header_code += '        return true;\n'
    header_code += '    }\n\n'
    header_code += 'private:'
    header_code += """
    template<typename TblType>
    static bool initialize(const std::string& path) {
        csv2::Reader<
            csv2::delimiter<','>, 
            csv2::quote_character<'"'>, 
            csv2::first_row_is_header<false>, 
            csv2::trim_policy::trim_whitespace
        > csv;
        if (!csv.mmap(path)) {
            return false;
        }
        std::vector<std::array<std::string, TblType::Row::value_size>> values{};
        int rowcount{ 0 };
        for (const auto& row : csv) {
            if (rowcount++ < 2) {
                continue;
            }
            std::array<std::string, TblType::Row::value_size> local;
            int idx{ 0 };
            for (const auto& cell : row) {
                std::string value;
                cell.read_value(value);
                erase_if(value, [](char c) { return c == '\\r' || c == '"'; });
                if (!value.empty()) {
                    local[idx++] = value;
                }
            }
            if (idx > 0) {
                values.push_back(local);
            }
        }
        TblType::initialize(values);
        return true;
    }
"""
    header_code += '};\n'

    header_code += '\n'
    header_code += "#endif // __TABLES_H__"

    with open(generate_path, 'w') as single_header_file:
        single_header_file.write(header_code)

def generate_table_class(data, file_name, class_name):
    members = data[0]
    types = data[1]

    cpp_code = f'// generated from {file_name}\n'
    cpp_code += f'class {class_name} {{\n'
    cpp_code += 'public:\n'
    cpp_code += '    struct Row {\n'
    cpp_code += f'        static constexpr int value_size = {len(members)};\n\n'

    key_member = ''
    key_type = ''
    is_first_column = True
    for member, type_ in zip(members, types):
        member_name = f"{member}_"
        
        if is_first_column:
            key_member = member
            key_type = type_

        if type_ == 'int':
            cpp_code += f"        int {member_name};"

        elif type_ == 'string':
            cpp_code += f"        std::string {member_name};"

        elif 'list<enum<' in type_ and '>>' in type_:
            enum_list_type = re.search(r'list<enum<(.+?)>>', type_).group(1)
            cpp_code += f"        std::vector<{enum_list_type}> {member_name};"

        elif 'list<' in type_ and '>' in type_:
            list_type = re.search(r'list<(.+?)>', type_).group(1)
            if list_type == 'string':
                list_type = 'std::string'
            
            cpp_code += f"        std::vector<{list_type}> {member_name};"

        elif 'enum<' in type_ and '>' in type_:
            enum_type = re.search(r'enum<(.+?)>', type_).group(1)
            cpp_code += f"        {enum_type} {member_name};"

        if is_first_column:
            key_member = member
            key_type = type_
            if type_ == 'string':
                key_type = 'std::string'
            
            is_first_column = False
            cpp_code += ' // key'
        
        cpp_code += '\n'

    cpp_code += '    };\n\n'

    cpp_code += f'    static const Row* get(const {key_type}& {key_member}) {{\n'
    cpp_code += f'        const auto it = _datas.find({key_member});\n'
    cpp_code += f'        if (it == std::end(_datas)) {{\n'
    cpp_code += f'            return nullptr;\n'
    cpp_code += f'        }}\n'
    cpp_code += f'        return &it->second;\n'
    cpp_code += f'    }}\n\n'

    cpp_code += f'private:\n'
    cpp_code += '    friend class TblLoader;\n\n'
    cpp_code += '    static void initialize(const std::vector<std::array<std::string, Row::value_size>>& rows) {\n'
    cpp_code += '        for (const auto& row : rows) {\n'
    cpp_code += '            _datas.emplace(std::piecewise_construct,\n'
    cpp_code += f'                std::forward_as_tuple('

    if key_type == 'std::string':
        cpp_code += "row[0]),\n"
    elif key_type == 'int':
        cpp_code += "std::stoi(row[0])),\n"

    cpp_code += f'                std::forward_as_tuple(\n'
    for i, (member, type_) in enumerate(zip(members, types)):
        if type_ == 'string':
            cpp_code += f"                    row[{i}]"
        elif type_ == 'int':
            cpp_code += f"                    std::stoi(row[{i}])"
        elif 'list<enum<' in type_ and '>>' in type_:
            enum_type = re.search(r'enum<(.+?)>', type_).group(1)
            cpp_code += f"                    split<{enum_type}>(row[{i}])"
        elif 'list<' in type_ and '>' in type_:
            list_type = re.search(r'list<(.+?)>', type_).group(1)
            if list_type == 'string':
                list_type = 'std::string'
            cpp_code += f"                    split<{list_type}>(row[{i}])"
        elif 'enum<' in type_ and '>' in type_:
            enum_type = re.search(r'enum<(.+?)>', type_).group(1)
            cpp_code += f"                    static_cast<{enum_type}>(std::stoi(row[{i}]))"

        if i != len(members) - 1:
            cpp_code += ",\n"

    cpp_code += '\n                ));\n'
    cpp_code += '        }\n'
    cpp_code += '    }\n\n'

    cpp_code += f'    inline static std::unordered_map<{key_type}, Row> _datas{{}};\n'
    cpp_code += f'}};\n'

    return cpp_code


def main():
    output_folder = './generated/'
    tables_folder = './Tables/'
    types_folder = './Types/'

    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    generate_table_from_csv(output_folder, tables_folder)
    generate_type_from_csv(output_folder, types_folder)

if __name__ == "__main__":
    main()
