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
  
| cuid | character_name | max_level | cost | character_type      | item_type      | requirement_quests | requirement_items    |
|------|----------------|-----------|------|---------------------|----------------|--------------------|----------------------|
| int  | string         | int       | int  | enum<CharacterType> | enum<ItemType> | list<string>       | list<enum<ItemType>> |
| 1    | emily          | 50        | 100  | 1                   | 1              | "1,2,3,4,5,6"      | "1,2,3,4"        |
| 2    | alexander      | 55        | 200  | 2                   | 2              | "1,2,3,4,5,7"      | "1,2,3,4"        |
| 3    | sophia         | 60        | 300  | 3                   | 3              | "1,2,3,4,5,8"      | "1,2,3,4"        |
| 4    | benjamin       | 30        | 300  | 4                   | 4              | "1,2,3,4,5,9"      | "1,2,3,4"        |
| 5    | olivia         | 50        | 300  | 5                   | 5              | "1,2,3,4,5,10"     | "1,2,3,4"       |
| 6    | william        | 40        | 300  | 6                   | 6              | "1,2,3,4,5,11"     | "1,2,3,4"       |
| 7    | ava            | 30        | 300  | 7                   | 7              | "1,2,3,4,5,12"     | "1,2,3,4"       |
| 8    | james          | 35        | 300  | 8                   | 8              | "1,2,3,4,5,13"     | "1,2,3,4"       |
| 9    | liam           | 36        | 300  | 9                   | 9              | "1,2,3,4,5,14"     | "1,2,3,4"       |
| 10   | isabella       | 37        | 300  | 0                   | 0              | "1,2,3,4,5,15"     | "1,2,3,4"       |

(TblCharacter.csv)


The script generates complex C++ code, but its usage is incredibly simple, as shown below.
```cpp
#include "./generated/Tables.hpp"

int main()
{
    TblLoader::initialize("codemaker/Tables");

    auto* d1 = TblCharacter::get(1);
    if (d1 != nullptr)
    {
        cout << d1->character_name_ << endl; // "emily"
        cout << d1->max_level_ << endl; // 50
        cout << d1->cost_ << endl; // 100
        for (const auto& item : d1->requirement_items_)
        {
            cout << EnumConverter<ItemType>::toString(item) << endl; 
        }
    }
}
```

output:
```
emily
50
100
AK47
AK74U
M16A2
M16A4
```

# Note
WIP
