// This file has been generated automatically. Don't modify it.

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
}

// generated from TblCharacter.csv
class TblCharacter {
public:
    struct Row {
        static constexpr int value_size = 8;

        int cuid_; // key
        std::string character_name_;
        int max_level_;
        int cost_;
        CharacterType character_type_;
        ItemType item_type_;
        std::vector<std::string> requirement_quests_;
        std::vector<ItemType> requirement_items_;
    };

    static const Row* get(const int& cuid) {
        const auto it = _datas.find(cuid);
        if (it == std::end(_datas)) {
            return nullptr;
        }
        return &it->second;
    }

private:
    friend class TblLoader;

    static void initialize(const std::vector<std::array<std::string, Row::value_size>>& rows) {
        for (const auto& row : rows) {
            _datas.emplace(std::piecewise_construct,
                std::forward_as_tuple(std::stoi(row[0])),
                std::forward_as_tuple(
                    std::stoi(row[0]),
                    row[1],
                    std::stoi(row[2]),
                    std::stoi(row[3]),
                    static_cast<CharacterType>(std::stoi(row[4])),
                    static_cast<ItemType>(std::stoi(row[5])),
                    split<std::string>(row[6]),
                    split<ItemType>(row[7])
                ));
        }
    }

    inline static std::unordered_map<int, Row> _datas{};
};

// generated from TblItem.csv
class TblItem {
public:
    struct Row {
        static constexpr int value_size = 6;

        std::string item_id_; // key
        std::string item_name_;
        ItemType item_type_;
        int item_level_;
        int cost_;
        int required_level_;
    };

    static const Row* get(const std::string& item_id) {
        const auto it = _datas.find(item_id);
        if (it == std::end(_datas)) {
            return nullptr;
        }
        return &it->second;
    }

private:
    friend class TblLoader;

    static void initialize(const std::vector<std::array<std::string, Row::value_size>>& rows) {
        for (const auto& row : rows) {
            _datas.emplace(std::piecewise_construct,
                std::forward_as_tuple(row[0]),
                std::forward_as_tuple(
                    row[0],
                    row[1],
                    static_cast<ItemType>(std::stoi(row[2])),
                    std::stoi(row[3]),
                    std::stoi(row[4]),
                    std::stoi(row[5])
                ));
        }
    }

    inline static std::unordered_map<std::string, Row> _datas{};
};

class TblLoader {
public:
    static bool initialize(const std::string& folderPath) {
        initialize<TblCharacter>(folderPath + "/TblCharacter.csv");
        initialize<TblItem>(folderPath + "/TblItem.csv");
        return true;
    }

private:
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
                erase_if(value, [](char c) { return c == '\r' || c == '"'; });
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
};

#endif // __TABLES_H__