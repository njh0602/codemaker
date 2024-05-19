#include <iostream>

#include "generated/Tables.hpp"
#include "generated/Types.hpp"
using std::cout;
using std::endl;

int main()
{
	if (TblLoader::initialize("Tables/") == false)
	{
		std::cout << "error" << std::endl;
	}

	std::cout << enum_str(CharacterType::e_alexander) << std::endl;
	std::cout << static_cast<int>(enum_value<CharacterType>("e_alexander")) << std::endl;

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

	cout << ame::TblItem2::get(2)->item_name_ << endl;
}