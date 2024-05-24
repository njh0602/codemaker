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