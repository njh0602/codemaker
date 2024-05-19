from jinja2 import Template
import os
import csv
import re

def get_namespace_from_path(path):
    parts = path.split(os.sep)
    namespace = '::'.join(parts)
    return namespace if namespace != '.' else ''

def generate_type_from_csv(output_folder, folder_path):
    enum_datas = []

    for root, _, files in os.walk(folder_path):
        csv_files = [f for f in files if f.endswith('.csv')]
        for file_name in csv_files:
            file_path = os.path.join(root, file_name)
            with open(file_path, newline='') as csvfile:
                csv_reader = csv.reader(csvfile)
                data = list(csv_reader)
                enum_values = []
                for enum_value in data:
                    # Comma-separated value; handle optional integer value
                    if len(enum_value) > 1:
                        name = enum_value[0].strip()
                        value = enum_value[1].strip()
                        enum_values.append((name, value))
                    else:
                        name = enum_value[0].strip()
                        enum_values.append((name, None))
                
                enum_datas.append({
                    'file_name': file_name,
                    'enum_name': os.path.splitext(file_name)[0],
                    'enum_values': enum_values,
                    'namespace': get_namespace_from_path(os.path.relpath(root, start=folder_path))
                })

    with open('./Templates/Types.hpp.template', 'r') as file:
        template_content = file.read()

    template = Template(template_content)
    cpp_code = template.render(enums=enum_datas)

    with open(os.path.join(output_folder, "Types.hpp"), 'w') as single_header_file:
        single_header_file.write(cpp_code)

def generate_table_from_csv(output_folder, folder_path):
    
    def convert_type_to_cpp(type_name, to_caster):

        def is_valid_enum_type(enum_type):
            if enum_type == 'string' or enum_type == 'int' or enum_type.startswith('list<'):
                return False
            return True

        def is_valid_normal_type(type_name):
            if type_name == 'string' or type_name == 'int':
                return True
            return False
    
        # string 타입
        if type_name == 'string':
            return ('', '') if to_caster else 'std::string'
    
        # int 타입
        elif type_name == 'int':
            return ('std::stoi(', ')') if to_caster else 'int'

        # list<enum<...>> 타입
        elif 'list<enum<' in type_name and '>>' in type_name:
            enum_type = re.search(r'list<enum<(.+?)>>', type_name).group(1)
            if not is_valid_enum_type(enum_type):
                return '<error_type>'
            return (f'split<{enum_type}>(', ')') if to_caster else f'std::vector<{enum_type}>'
        
        # list<...> 타입
        elif 'list<' in type_name and '>' in type_name:
            list_type = re.search(r'list<(.+?)>', type_name).group(1)
            if not is_valid_normal_type(list_type):
                return '<error_type>'
            return (f'split<{convert_type_to_cpp(list_type, to_caster=False)}>(', ')') if to_caster else f'std::vector<{convert_type_to_cpp(list_type, to_caster=False)}>'

        # enum 타입
        elif 'enum<' in type_name and '>' in type_name:
            enum_type = re.search(r'enum<(.+?)>', type_name).group(1)
            if not is_valid_enum_type(enum_type):
                return '<error_type>'
            return (f'static_cast<{enum_type}>(std::stoi(', '))') if to_caster else enum_type
    
        # 지원하지 않는 타입
        return '<error_type>'

    class_datas = []
    
    for root, _, files in os.walk(folder_path):
        csv_files = [f for f in files if f.endswith('.csv')]
        for file_name in csv_files:
            file_path = os.path.join(root, file_name)
            with open(file_path, newline='') as csvfile:
                csv_reader = csv.reader(csvfile)
                data = list(csv_reader)
                
                type_names = data[1]
                member_names = data[0]

                members = []
                member_casters = []
                for type_name, member_name in zip(type_names, member_names):
                    members.append((convert_type_to_cpp(type_name, to_caster=False), member_name))
                    member_casters.append(convert_type_to_cpp(type_name, to_caster=True))

                class_datas.append({
                    'file_name': file_name, 
                    'class_name': os.path.splitext(file_name)[0],
                    'value_size': len(member_names),
                    'key_member': member_names[0],
                    'key_type': convert_type_to_cpp(type_names[0], to_caster=False),
                    'members': members,
                    'member_casters': member_casters,
                    'namespace': get_namespace_from_path(os.path.relpath(root, start=folder_path))
            })

    with open('./Templates/Tables.hpp.template', 'r') as file:
        template_content = file.read()

    template = Template(template_content)
    cpp_code = template.render(classes=class_datas)

    with open(os.path.join(output_folder, "Tables.hpp"), 'w') as single_header_file:
        single_header_file.write(cpp_code)

def main():
    # header 생성 폴더 경로
    output_folder = './generated/'

    # table 데이터 폴더 경로
    tables_folder = './Tables/'

    # type 데이터 폴더 경로
    types_folder = './Types/'

    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    generate_table_from_csv(output_folder, tables_folder)
    generate_type_from_csv(output_folder, types_folder)

if __name__ == "__main__":
    main()
