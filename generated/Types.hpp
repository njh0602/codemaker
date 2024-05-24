// This file has been generated automatically. Don't modify it.

#ifndef __GENERATED_TYPES_H__
#define __GENERATED_TYPES_H__

#include <array>
#include <string>
#include <unordered_map>

template<typename T>
struct enum_helpers;

template<typename T>
inline constexpr std::size_t enum_count = 0;

template<typename T> 
std::string enum_str(T value);

template<typename T> 
T enum_value(const std::string& str);

template<typename T>
const std::array<T, enum_count<T>>& enum_values();

template<typename T>
bool is_valid_enum(T value);

template<typename T>
bool is_valid_enum(const std::string& str);

template<typename T>
bool is_valid_enum(int value);

static const std::string k_empty_str;

// Generated from CharacterType.csv

enum class CharacterType {
    e_invalid = -65535, // this value is generated
    e_emily = 1, 
    e_alexander = 2, 
    e_sophia = 3, 
    e_benjamin = 4, 
    e_olivia = 1000, 
    e_william = 1001, 
    e_ava = 1002, 
    e_james = 2000, 
    e_liam = 2001, 
    e_isabella = 3000
};

template<> struct enum_helpers<CharacterType> {
    static CharacterType enum_value(const std::string& str) {
        static const std::unordered_map<std::string, CharacterType> enum_table {
            {"e_invalid", CharacterType::e_invalid},
            {"e_emily", CharacterType::e_emily},
            {"e_alexander", CharacterType::e_alexander},
            {"e_sophia", CharacterType::e_sophia},
            {"e_benjamin", CharacterType::e_benjamin},
            {"e_olivia", CharacterType::e_olivia},
            {"e_william", CharacterType::e_william},
            {"e_ava", CharacterType::e_ava},
            {"e_james", CharacterType::e_james},
            {"e_liam", CharacterType::e_liam},
            {"e_isabella", CharacterType::e_isabella},
        };
        auto it = enum_table.find(str);
        if (it == enum_table.end()) {
            return CharacterType::e_invalid;
        }
        return it->second;
    }

    static const std::string& enum_str(CharacterType value) {
        static const std::unordered_map<CharacterType, std::string> str_map {
            { CharacterType::e_invalid, "e_invalid"},
            { CharacterType::e_emily, "e_emily"},
            { CharacterType::e_alexander, "e_alexander"},
            { CharacterType::e_sophia, "e_sophia"},
            { CharacterType::e_benjamin, "e_benjamin"},
            { CharacterType::e_olivia, "e_olivia"},
            { CharacterType::e_william, "e_william"},
            { CharacterType::e_ava, "e_ava"},
            { CharacterType::e_james, "e_james"},
            { CharacterType::e_liam, "e_liam"},
            { CharacterType::e_isabella, "e_isabella"},
        };
        auto it = str_map.find(value);
        if (it == str_map.end()) {
            return k_empty_str;
        }
        return it->second;
    }

    static const std::array<CharacterType, 10>& enum_values() {
        static const std::array<CharacterType, 10> enums {
            // CharacterType::e_invalid,
            CharacterType::e_emily,
            CharacterType::e_alexander,
            CharacterType::e_sophia,
            CharacterType::e_benjamin,
            CharacterType::e_olivia,
            CharacterType::e_william,
            CharacterType::e_ava,
            CharacterType::e_james,
            CharacterType::e_liam,
            CharacterType::e_isabella,
        };
        return enums;
    }
};


template<>
inline constexpr std::size_t enum_count<CharacterType> = 10;

template<>
inline std::string enum_str<CharacterType>(CharacterType value) {
    return enum_helpers<CharacterType>::enum_str(value);
}

template<>
inline CharacterType enum_value<CharacterType>(const std::string& str) {
    return enum_helpers<CharacterType>::enum_value(str);
}

template<>
inline const std::array<CharacterType, enum_count<CharacterType>>& enum_values() {
    return enum_helpers<CharacterType>::enum_values();
}

template<>
inline bool is_valid_enum<CharacterType>(CharacterType value) {
    const auto& found_str = enum_helpers<CharacterType>::enum_str(value);
    return found_str != "e_invalid" && found_str.empty() == false;
}

template<>
inline bool is_valid_enum<CharacterType>(const std::string& str) {
    return enum_helpers<CharacterType>::enum_value(str) != CharacterType::e_invalid;
}

template<>
inline bool is_valid_enum<CharacterType>(int value) {
    return is_valid_enum(static_cast<CharacterType>(value));
}


// Generated from ItemType.csv
namespace Game { 
enum class ItemType {
    e_invalid = -65535, // this value is generated
    MK18_MOD1 = 0, 
    AK47 = 1, 
    AK74U = 2, 
    M16A2 = 3, 
    M16A4 = 4, 
    MP5SD = 5, 
    MP7A2 = 6, 
    GLOCK19 = 7, 
    Remington700 = 8, 
    FN_SCARL = 9, 
    FN_SCARH = 10, 
    SIG_Sauer_P226 = 11, 
    Beretta_M9 = 12, 
    Mossberg500 = 13, 
    Winchester_Model_70 = 14, 
    Steyr_AUG = 15, 
    HK_G36 = 16, 
    Ruger_Mini14 = 17
};

template<> struct enum_helpers<ItemType> {
    static ItemType enum_value(const std::string& str) {
        static const std::unordered_map<std::string, ItemType> enum_table {
            {"e_invalid", ItemType::e_invalid},
            {"MK18_MOD1", ItemType::MK18_MOD1},
            {"AK47", ItemType::AK47},
            {"AK74U", ItemType::AK74U},
            {"M16A2", ItemType::M16A2},
            {"M16A4", ItemType::M16A4},
            {"MP5SD", ItemType::MP5SD},
            {"MP7A2", ItemType::MP7A2},
            {"GLOCK19", ItemType::GLOCK19},
            {"Remington700", ItemType::Remington700},
            {"FN_SCARL", ItemType::FN_SCARL},
            {"FN_SCARH", ItemType::FN_SCARH},
            {"SIG_Sauer_P226", ItemType::SIG_Sauer_P226},
            {"Beretta_M9", ItemType::Beretta_M9},
            {"Mossberg500", ItemType::Mossberg500},
            {"Winchester_Model_70", ItemType::Winchester_Model_70},
            {"Steyr_AUG", ItemType::Steyr_AUG},
            {"HK_G36", ItemType::HK_G36},
            {"Ruger_Mini14", ItemType::Ruger_Mini14},
        };
        auto it = enum_table.find(str);
        if (it == enum_table.end()) {
            return ItemType::e_invalid;
        }
        return it->second;
    }

    static const std::string& enum_str(ItemType value) {
        static const std::unordered_map<ItemType, std::string> str_map {
            { ItemType::e_invalid, "e_invalid"},
            { ItemType::MK18_MOD1, "MK18_MOD1"},
            { ItemType::AK47, "AK47"},
            { ItemType::AK74U, "AK74U"},
            { ItemType::M16A2, "M16A2"},
            { ItemType::M16A4, "M16A4"},
            { ItemType::MP5SD, "MP5SD"},
            { ItemType::MP7A2, "MP7A2"},
            { ItemType::GLOCK19, "GLOCK19"},
            { ItemType::Remington700, "Remington700"},
            { ItemType::FN_SCARL, "FN_SCARL"},
            { ItemType::FN_SCARH, "FN_SCARH"},
            { ItemType::SIG_Sauer_P226, "SIG_Sauer_P226"},
            { ItemType::Beretta_M9, "Beretta_M9"},
            { ItemType::Mossberg500, "Mossberg500"},
            { ItemType::Winchester_Model_70, "Winchester_Model_70"},
            { ItemType::Steyr_AUG, "Steyr_AUG"},
            { ItemType::HK_G36, "HK_G36"},
            { ItemType::Ruger_Mini14, "Ruger_Mini14"},
        };
        auto it = str_map.find(value);
        if (it == str_map.end()) {
            return k_empty_str;
        }
        return it->second;
    }

    static const std::array<ItemType, 18>& enum_values() {
        static const std::array<ItemType, 18> enums {
            // ItemType::e_invalid,
            ItemType::MK18_MOD1,
            ItemType::AK47,
            ItemType::AK74U,
            ItemType::M16A2,
            ItemType::M16A4,
            ItemType::MP5SD,
            ItemType::MP7A2,
            ItemType::GLOCK19,
            ItemType::Remington700,
            ItemType::FN_SCARL,
            ItemType::FN_SCARH,
            ItemType::SIG_Sauer_P226,
            ItemType::Beretta_M9,
            ItemType::Mossberg500,
            ItemType::Winchester_Model_70,
            ItemType::Steyr_AUG,
            ItemType::HK_G36,
            ItemType::Ruger_Mini14,
        };
        return enums;
    }
};
} // namespace Game 

template<>
inline constexpr std::size_t enum_count<Game::ItemType> = 18;

template<>
inline std::string enum_str<Game::ItemType>(Game::ItemType value) {
    return enum_helpers<Game::ItemType>::enum_str(value);
}

template<>
inline Game::ItemType enum_value<Game::ItemType>(const std::string& str) {
    return enum_helpers<Game::ItemType>::enum_value(str);
}

template<>
inline const std::array<Game::ItemType, enum_count<Game::ItemType>>& enum_values() {
    return enum_helpers<Game::ItemType>::enum_values();
}

template<>
inline bool is_valid_enum<Game::ItemType>(Game::ItemType value) {
    const auto& found_str = enum_helpers<Game::ItemType>::enum_str(value);
    return found_str != "e_invalid" && found_str.empty() == false;
}

template<>
inline bool is_valid_enum<Game::ItemType>(const std::string& str) {
    return enum_helpers<Game::ItemType>::enum_value(str) != Game::ItemType::e_invalid;
}

template<>
inline bool is_valid_enum<Game::ItemType>(int value) {
    return is_valid_enum(static_cast<Game::ItemType>(value));
}


#endif // __GENERATED_TYPES_H__