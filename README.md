# Code maker
This python script generates C++ manager classes to easily access design data used in game development.

# Concept
A single CSV file represents both the schema and the data. 
If you place dozens or hundreds of CSV files in the same folder, an equal number of C++ classes will be generated into a single header file. To use these, you just need to include this header file.

# Example
The following CSV file will be generated into the following C++ code.
- The first and second rows are used as metadata for the generated data code. (first row: member names, second row: member types)
- The supported types currently include int, string, enum, and list. 
- The first column serves as the key value for that row, while the rest is stored as data.
  
| **cuid** | **character\_name** | **max\_level** | **cost** | **character\_type** | **item\_type** | **requirement\_quests** | **requirement\_items** |
|:--------:|:-------------------:|:--------------:|:--------:|:-------------------:|:--------------:|:-----------------------:|:----------------------:|
| **int**  | string              | int            | int      | enum&lt;CharacterType&gt; | enum&lt;ItemType&gt; | list&lt;string&gt;            | list&lt;enum&lt;ItemType&gt;&gt;   |
| **1**    | emily               | 50             | 100      | 1                   | 1              | "1,2,3,4,5,6"           | "1,2,3,4,5,6"          |
| **2**    | alexander           | 55             | 200      | 2                   | 2              | "1,2,3,4,5,7"           | "1,2,3,4,5,7"          |
| **3**    | sophia              | 60             | 300      | 3                   | 3              | "1,2,3,4,5,8"           | "1,2,3,4,5,8"          |
| **4**    | benjamin            | 30             | 300      | 4                   | 4              | "1,2,3,4,5,9"           | "1,2,3,4,5,9"          |
| **5**    | olivia              | 50             | 300      | 5                   | 5              | "1,2,3,4,5,10"          | "1,2,3,4,5,10"         |
| **6**    | william             | 40             | 300      | 6                   | 6              | "1,2,3,4,5,11"          | "1,2,3,4,5,11"         |
| **7**    | ava                 | 30             | 300      | 7                   | 7              | "1,2,3,4,5,12"          | "1,2,3,4,5,12"         |
| **8**    | james               | 35             | 300      | 8                   | 8              | "1,2,3,4,5,13"          | "1,2,3,4,5,13"         |
| **9**    | liam                | 36             | 300      | 9                   | 9              | "1,2,3,4,5,14"          | "1,2,3,4,5,14"         |
| **10**   | isabella            | 37             | 300      | 0                   | 0              | "1,2,3,4,5,15"          | "1,2,3,4,5,15"         |

(TblCharacter.csv)

| **item_id** | **item_name** | **item_type** | **item_level** | **cost** | **required_level** |
|:-----------:|:-------------:|:-------------:|:--------------:|:--------:|:-----------------:|
|    int      |     string    | enum&lt;ItemType&gt; |      int       |   int    |        int        |
|      1      |    sword      |       0       |      100       |    1     |         1         |
|      2      |    shield     |       1       |      200       |    2     |         2         |
|      3      |    potion     |       1       |      300       |    3     |         3         |
|      4      |  bow weapon   |       2       |      300       |    4     |         4         |
|      5      |    staff      |       3       |      300       |    5     |         5         |
|      6      |     robe      |       4       |      300       |    6     |         6         |
|      7      |     ring      |       5       |      300       |    7     |         7         |
|      8      |    scroll     |       6       |      300       |    8     |         8         |
|      9      |     axe       |       7       |      300       |    9     |         9         |
|     10      |    helmet     |       8       |      300       |    0     |         0         |

(TblItem.csv)

| MK18_MOD1 |
|-----------|
| AK47      |
| AK74U     |
| M16A2     |
| M16A4     |
| MP5SD     |
| MP7A2     |
| GLOCK19   |

(ItemType.csv)

The script generates complex C++ code, but its usage is incredibly simple, as shown below.
```cpp
#include <iostream>

#include "generated/types.hpp"
#include "generated/tables.hpp"
using std::cout;
using std::endl;

int main()
{
	cout << "test1. types ---------" << endl;
	for (const auto& e : enum_values<CharacterType>())
	{
		cout << static_cast<int>(e) << "(" << enum_str(e) << ")" << endl;
	}
	cout << "CharacterType's enum count:" << enum_count<CharacterType> << endl; // 10

	if (is_valid_enum<CharacterType>("invalid name")) 
		cout << "valid" << endl;
	else  
		cout << "CharacterType::invalid name is invalid" << endl; // display

	if (is_valid_enum(Game::ItemType::e_invalid)) 
		cout << "valid" << endl;
	else  
		cout << "Game::ItemType::e_invalid is invalid" << endl; // display

	if (is_valid_enum(Game::ItemType::AK47)) 
		cout << "Game::ItemType::AK47 is valid" << endl; // display
	else  
		cout << "invalid" << endl;

	if (is_valid_enum<Game::ItemType>(42)) 
		cout << "valid" << endl;
	else  
		cout << "Game::ItemType::42 is invalid" << endl; // display

	if (is_valid_enum<Game::ItemType>(0)) 
		cout << "Game::ItemType::0 is valid(" << enum_str(static_cast<Game::ItemType>(0)) << ")" << endl; // display
	else  cout << "invalid" << endl;

	cout << "test2. tables ---------" << endl;
	if (TblLoader::initialize("tables/") == false)
	{
		std::cout << "error" << std::endl;
		return 0;
	}

	cout << TblCharacter::get(1)->character_name_ << endl;
	if (auto p = TblCharacter::get(14); p != nullptr)
	{
		cout << enum_str(p->item_type_) << endl;
	}
	if (auto p = TblCharacter::get(1); p != nullptr)
	{
		cout << enum_str(p->item_type_) << endl;
	}
	if (auto p = TblCharacter::get(2); p != nullptr)
	{
		cout << enum_str(p->item_type_) << endl;
	}

	cout << game::TblItem::get("2")->item_name_ << endl;
}
```

output:
```
test1. types ---------
1(e_emily)
2(e_alexander)
3(e_sophia)
4(e_benjamin)
1000(e_olivia)
1001(e_william)
1002(e_ava)
2000(e_james)
2001(e_liam)
3000(e_isabella)
CharacterType's enum count:10
CharacterType::invalid name is invalid
Game::ItemType::e_invalid is invalid
Game::ItemType::AK47 is valid
Game::ItemType::42 is invalid
Game::ItemType::0 is valid(MK18_MOD1)
test2. tables ---------
emily
AK47
AK74U
shield
```

# Note
WIP
