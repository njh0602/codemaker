// This file has been generated automatically. Don't modify it.

#ifndef __TYPES_H__
#define __TYPES_H__

#include <string>
#include <unordered_map>

template<typename T>
struct EnumConverter;

static const std::string EmptyString{};

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

template<> struct EnumConverter<CharacterType> {
    static CharacterType fromString(const std::string& str) {
        static const std::unordered_map<std::string, CharacterType> enumMap {
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
        auto it = enumMap.find(str);
        if (it == enumMap.end()) {
            return CharacterType{};
        }
        return it->second;
    }

    static const std::string& toString(CharacterType enumValue) {
        static const std::unordered_map<CharacterType, std::string> strMap {
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
        auto it = strMap.find(enumValue);
        if (it == strMap.end()) {
            return EmptyString;
        }
        return it->second;
    }
};

// Generated from ItemType.csv
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

template<> struct EnumConverter<ItemType> {
    static ItemType fromString(const std::string& str) {
        static const std::unordered_map<std::string, ItemType> enumMap {
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
        auto it = enumMap.find(str);
        if (it == enumMap.end()) {
            return ItemType{};
        }
        return it->second;
    }

    static const std::string& toString(ItemType enumValue) {
        static const std::unordered_map<ItemType, std::string> strMap {
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
        auto it = strMap.find(enumValue);
        if (it == strMap.end()) {
            return EmptyString;
        }
        return it->second;
    }
};

#endif // __TYPES_H__