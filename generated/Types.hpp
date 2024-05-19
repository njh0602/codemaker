// This file has been generated automatically. Don't modify it.

#ifndef __TYPES_H__
#define __TYPES_H__

#include <string>
#include <unordered_map>

template<typename T>
struct enum_converter;

template<typename T> 
std::string enum_str(T value);

template<typename T> 
T enum_value(const std::string& str);

static const std::string k_empty_str;

// Generated from CharacterType.csv

enum class CharacterType {
    e_emily = 0,
    e_alexander = 1,
    e_sophia = 2,
    e_benjamin = 3,
    e_olivia = 4,
    e_william = 5,
    e_ava = 6,
    e_james = 7,
    e_liam = 8,
    e_isabella = 9
};

template<> struct enum_converter<CharacterType> {
    static CharacterType enum_value(const std::string& str) {
        static const std::unordered_map<std::string, CharacterType> enum_table {
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
            return CharacterType{};
        }
        return it->second;
    }

    static const std::string& enum_str(CharacterType value) {
        static const std::unordered_map<CharacterType, std::string> str_map {
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
};


// helper functions
template<> 
inline std::string enum_str<CharacterType>(CharacterType value) {
    return enum_converter<CharacterType>::enum_str(value);
}

template<>
inline CharacterType enum_value<CharacterType>(const std::string& str) {
     return enum_converter<CharacterType>::enum_value(str);
}

// Generated from ItemType.csv
namespace Game { 
enum class ItemType {
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

template<> struct enum_converter<ItemType> {
    static ItemType enum_value(const std::string& str) {
        static const std::unordered_map<std::string, ItemType> enum_table {
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
            return ItemType{};
        }
        return it->second;
    }

    static const std::string& enum_str(ItemType value) {
        static const std::unordered_map<ItemType, std::string> str_map {
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
};
} // namespace Game 

// helper functions
template<> 
inline std::string enum_str<Game::ItemType>(Game::ItemType value) {
    return enum_converter<Game::ItemType>::enum_str(value);
}

template<>
inline Game::ItemType enum_value<Game::ItemType>(const std::string& str) {
     return enum_converter<Game::ItemType>::enum_value(str);
}

// Generated from CharacterType2.csv
namespace Game::Entity { 
enum class CharacterType2 {
    e_emily = 0,
    e_alexander = 1,
    e_sophia = 2,
    e_benjamin = 3,
    e_olivia = 4,
    e_william = 5,
    e_ava = 6,
    e_james = 7,
    e_liam = 8,
    e_isabella = 9
};

template<> struct enum_converter<CharacterType2> {
    static CharacterType2 enum_value(const std::string& str) {
        static const std::unordered_map<std::string, CharacterType2> enum_table {
            {"e_emily", CharacterType2::e_emily},
            {"e_alexander", CharacterType2::e_alexander},
            {"e_sophia", CharacterType2::e_sophia},
            {"e_benjamin", CharacterType2::e_benjamin},
            {"e_olivia", CharacterType2::e_olivia},
            {"e_william", CharacterType2::e_william},
            {"e_ava", CharacterType2::e_ava},
            {"e_james", CharacterType2::e_james},
            {"e_liam", CharacterType2::e_liam},
            {"e_isabella", CharacterType2::e_isabella},
        };
        auto it = enum_table.find(str);
        if (it == enum_table.end()) {
            return CharacterType2{};
        }
        return it->second;
    }

    static const std::string& enum_str(CharacterType2 value) {
        static const std::unordered_map<CharacterType2, std::string> str_map {
            { CharacterType2::e_emily, "e_emily"},
            { CharacterType2::e_alexander, "e_alexander"},
            { CharacterType2::e_sophia, "e_sophia"},
            { CharacterType2::e_benjamin, "e_benjamin"},
            { CharacterType2::e_olivia, "e_olivia"},
            { CharacterType2::e_william, "e_william"},
            { CharacterType2::e_ava, "e_ava"},
            { CharacterType2::e_james, "e_james"},
            { CharacterType2::e_liam, "e_liam"},
            { CharacterType2::e_isabella, "e_isabella"},
        };
        auto it = str_map.find(value);
        if (it == str_map.end()) {
            return k_empty_str;
        }
        return it->second;
    }
};
} // namespace Game::Entity 

// helper functions
template<> 
inline std::string enum_str<Game::Entity::CharacterType2>(Game::Entity::CharacterType2 value) {
    return enum_converter<Game::Entity::CharacterType2>::enum_str(value);
}

template<>
inline Game::Entity::CharacterType2 enum_value<Game::Entity::CharacterType2>(const std::string& str) {
     return enum_converter<Game::Entity::CharacterType2>::enum_value(str);
}

#endif // __TYPES_H__