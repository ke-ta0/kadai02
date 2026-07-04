#include <iostream>
#include"Character.h"
#include<stdbool.h>
#include<time.h>
int main()
{
	// ランダムでHP設定
	srand((unsigned)time(NULL));

	// プレイヤー初期
	Player p;
	p.name = "Player";
	p.HP = rand() % 51 + 50;
	std::cout << p.name << "," << p.HP << std::endl;

	// スライム初期
	Enemy Slime;
	Slime.name = "Slime";
	Slime.HP = rand() % 51 + 50;
	std::cout << Slime.name << "," << Slime.HP << std::endl;

	// ゴブリンの初期
	Enemy Gobrin;
	Gobrin.name = "Gobrin";
	Gobrin.HP = rand() % 51 + 50;
	std::cout << Gobrin.name << "," << Gobrin.HP << std::endl;

	std::cout << "" << std::endl;
	while (true)
	{
		// 自分か敵がHP0になったらループから抜ける
		if (p.HP <= 0 || Slime.HP <= 0 && Gobrin.HP <= 0)
		{
			if (p.HP <= 0)
			{
				std::cout << "敵軍団の勝ち" << std::endl;
			}
			else if (Slime.HP <= 0 && Gobrin.HP <= 0)
			{
				std::cout << "Playerの勝ち" << std::endl;
			}
			break;
		}

		// player処理
		std::cout << "Playerのターン" << std::endl;
		p.isPlayer = true;
		int Attack = p.Attacking();

		// スライムのHPが0なら
		Slime.HP -= Attack; if (Slime.HP <= 0)
		{
			Gobrin.HP -= Attack;
			std::cout << "ゴブリンに" << Attack << "ダメージ" << std::endl;
		}

		else {
			std::cout << "スライムに" << Attack << "ダメージ" << std::endl;
		}
		
		
		std::cout << "" << std::endl;

		if (Slime.HP >= 0)
		{
			// スライム処理
			std::cout << "Slimeのターン" << std::endl;
			Slime.isPlayer = false;
			int SAttack = Slime.Attacking();
			p.HP -= SAttack;
			std::cout << "Playerに" << SAttack << "ダメージ" << std::endl;
			std::cout << "" << std::endl;
		}
		else if(Slime.HP <= 0)
		{
			std::cout<< ""<<std::endl;
		}

		if (Gobrin.HP >= 0)
		{
			// ゴブリン処理
			std::cout << "Gobrinのターン" << std::endl;
			Gobrin.isPlayer = false;
			int GAttack = Gobrin.Attacking();
			p.HP -=GAttack;
			std::cout << "Playerに" << GAttack << "ダメージ" << std::endl;
		}
		std::cout << "" << std::endl;

		//int MaxDamage;
		//if(MaxDamage)
		//
		p.turnEnd(p.name, p.HP);
		Slime.turnEnd(Slime.name,Slime.HP);
		Gobrin.turnEnd(Gobrin.name, Gobrin.HP);

		std::cout << "" << std::endl;

	}
}