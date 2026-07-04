#include "Character.h"
#include<iostream>

int Character::Attacking()
{
	if (isPlayer)
	{
		Attack = rand() % 20 + 1;
	}
	if (!isPlayer)
	{
		Attack = rand() % 10 + 1;
	}
	return Attack;
}

void Character::Die(const char* name)
{
	// ‘Ì—Í‚È‚­‚È‚Á‚½‚ç‚â‚ç‚ê‚½‚Å‚é
	if (HP <= 0)
	{
		std::cout << name << "‚â‚ç‚ê‚Ü‚µ‚½" << std::endl;
	}
	
}
void Character::turnEnd(const char*name,int HP)
{
	// Œ»Ý‚Ì‘Ì—Í
	std::cout <<name << "Žc‚èHP = " << HP << std::endl;
}