#pragma once
#include<stdbool.h>
#include<time.h>



	class Character
	{
	public:
		const char* name;
		int HP;
		int Attack;
		bool isPlayer = false;
		
	//Character();
	public:
		int Attacking();
		void Die(const char* name);
		void turnEnd(const char* name,int HP);
	};
	// åpè≥
	struct Player:Character
	{
		const char* name;
		int HP;
		int Attack;
	};
	// åpè≥
	struct Enemy : Character
	{
		const char* name;
		int HP;
		int Attack;
	};


