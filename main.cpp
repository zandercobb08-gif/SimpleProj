
#include <iostream>
#include <cstdlib>
#include "Utilities.h"
#include "player.h"
#include "enemy.h"
#include "Filefuncs.h"



int main()
{

	fileop("Game opened");
	srand(time(NULL));
	int cycles = 0;
	int ragetimer = 0;
	int logicenemy;
	int highscore = 0;
	bool lose = false;
	player hero;
	hero.getname();
	if (hero.name == "Siffrid") {
		difmult = 1.2;
	}
	highscore = printhighscore();
	cout << "Your highscore: " << highscore << endl;
	cout << "how many monsters stand in your way?" << endl;
	cin >> logicenemy;
	if (std::cin.fail() || logicenemy <= 0)
	{
		std::cout << "That's not a valid number, setting to 3." << std::endl;
		std::cin.clear();    // clear the error
		std::cin.ignore();    // empty cin (so we forget about the bad input)
		logicenemy = 3;
	}
	cycles = 3 - logicenemy;
	fileop("Setup logic complete");
	spacing();
	while (cycles < 3) {
		active = rand() % 3;
		if (active == GOBLIN) {
			opponent goblin;
			int damage = goblin.getenemydamage();
			int hp = goblin.getenemyhealth();
			int herodamage = hero.damagedealt();
			int heal;
			int choice;
			bool rage = false;

			int blades;
			int damagemult = 1;
			cout << "A goblin blocks the way!" << endl;
			while (hp > 0) {
				//logic for player choice
				if (rage)
					damagemult = 2;
				else
					damagemult = 1;
				bool alive = true;
				bool defending = false;
				if (ragetimer <= 0)
					rage = false;
				cout << "What will you do" << endl;
				cout << "Remaining health: " << hero.hp << endl;
				cout << "1. Attack" << endl;
				cout << "2. Defend" << endl;
				if (hero.potions > 0) {
					cout << "3. Use health potion. Potions remaing: " << hero.potions << endl;
				}
				if (daggerskill == true) {
					if (daggercooldown <= 0) {
						cout << "4. Use dagger skill" << endl;
					}
					else {
						cout << "On cooldown for " << daggercooldown << " more turns" << endl;

					}
				}
				if (swordskill == true) {
					if (swordcooldown <= 0) {
						cout << "5. sword skill" << endl;
					}
					else {
						cout << "On cooldown for " << swordcooldown << " more turns" << endl;
					}
				}
				if (pikeskill == true) {
					if (pikecooldown <= 0) {
						cout << "6. pike skill" << endl;
					}
					else {
						cout << "On cooldown for " << swordcooldown << " more turns" << endl;
					}
				}
				cin >> choice;
				if (std::cin.fail())
				{
					std::cout << "That's not a valid option, forcing defend." << std::endl;
					std::cin.clear();    // clear the error
					std::cin.ignore();    // empty cin (so we forget about the bad input)
					choice = 2;
				}
				switch (choice) {
				case 1:
					hp = hp - herodamage * damagemult;
					cout << hero.name <<" dealt " << herodamage * damagemult << " damage!" << endl;
					break;
				case 2:
					defending = true;
					cout << hero.name << " defended!" << hero.name << " will take less damage this turn." << endl;
					break;
				case 3:
					heal = rand() % 15 + 20;
					hero.hp += heal;
					cout << hero.name << " healed " << heal << " health!" << endl;
					if (hero.hp > 100)
						hero.hp = 100;
					hero.potions -= 1;
					break;
				case 4:
					if (daggerskill && daggercooldown <= 0) {
						cout << hero.name << " summons a swarm of blades!" << endl;
						blades = rand() % 4 + 1;
						cout << blades << " blades fly at your target!" << endl;
						while (blades > 0) {
							blades--;
							herodamage = rand() % 5 + 5;
							cout << "The blade does " << herodamage * damagemult << " damage!" << endl;
						}
					}
					daggercooldown = 5;
					break;
				case 5:
					if (swordskill && swordcooldown <= 0) {
						cout << "Fury flows through "<< hero.name << "!" << endl;
						rage = true;
						ragetimer = 2;
						swordcooldown = 5;

					}
					break;
				case 6:
					if (pikeskill && pikecooldown <= 0) {
						cout << "A stunning blow does " << herodamage * damagemult << endl;
						hp -= herodamage * damagemult;
						stun = true;
						pikecooldown = 5;
					}
					break;
				default:
					cout <<  "Invalid input. Forcing Defend." << endl;
					defending = true;
					cout << hero.name << " defended!" << hero.name << " will take less damage this turn." << endl;
					break;
				}


				//is enemy alive
				if (hp <= 0) {
					alive = false;
					cout << "The goblin falls!" << endl;
					if (hero.currentweapon != PIKE && hero.currentweapon != SWORD)
						hero.currentweapon = DAGGER;
					daggerskill = true;
					hero.potions += 1;
					cout << hero.name << " gained a dagger!" << endl;
					cout << hero.name << " also gained 1 potion" << endl;
					daggercooldown--;
					swordcooldown--;
					pikecooldown--;
					cycles += 1;
					ragetimer = 0;


				}
				//enemy turn
				if (alive && stun == false) {

					cout << "The goblin attacked" << endl;
					if (!defending) {
						hero.hp -= damage;
						cout << hero.name << " take's " << damage << " damage!" << endl;
					}
					else if (defending) {
						hero.hp -= damage / 2;
						cout << hero.name << " take's " << damage / 2 << " damage!" << endl;
					}
					daggercooldown--;
					swordcooldown--;
					pikecooldown--;
					ragetimer--;
				}
				else
					stun = false;
				spacing();
				if (hero.hp <= 0)
					lose = true;
				if (lose)
					break;
			}
		}
		if (active == SKELETON) {
			opponent skeleton;
			int damage = skeleton.getenemydamage();
			int hp = skeleton.getenemyhealth();
			int herodamage = hero.damagedealt();
			int heal;
			int choice;

			bool rage = false;
			int blades;
			int damagemult = 1;
			cout << "An undead skeleton shambles infront of you!" << endl;
			while (hp > 0) {

				//logic for player choice
				if (rage)
					damagemult = 2;
				else
					damagemult = 1;
				bool alive = true;
				bool defending = false;
				if (ragetimer <= 0)
					rage = false;
				cout << "What will you do" << endl;
				cout << "Remaining health: " << hero.hp << endl;
				cout << "1. Attack" << endl;
				cout << "2. Defend" << endl;
				if (hero.potions > 0) {
					cout << "3. Use health potion. Potions remaing: " << hero.potions << endl;
				}
				if (daggerskill == true) {
					if (daggercooldown <= 0) {
						cout << "4. Use dagger skill" << endl;
					}
					else {
						cout << "On cooldown for " << daggercooldown << " more turns" << endl;

					}
				}
				if (swordskill == true) {
					if (swordcooldown <= 0) {
						cout << "5. sword skill" << endl;
					}
					else {
						cout << "On cooldown for " << swordcooldown << " more turns" << endl;
					}
				}
				cin >> choice;
				if (std::cin.fail())
				{
					std::cout << "That's not a valid option, forcing defend." << std::endl;
					std::cin.clear();    // clear the error
					std::cin.ignore();    // empty cin (so we forget about the bad input)
					choice = 2;
				}
				switch (choice) {
				case 1:
					hp = hp - herodamage * damagemult;
					cout << hero.name << " dealt " << herodamage * damagemult << " damage!" << endl;
					break;
				case 2:
					defending = true;
					cout << hero.name << " defended!"<< hero.name << " will take less damage this turn." << endl;
					break;
				case 3:
					heal = rand() % 15 + 20;
					hero.hp += heal;
					cout << hero.name << " healed " << heal << " health!" << endl;
					if (hero.hp > 100)
						hero.hp = 100;
					hero.potions -= 1;
					break;
				case 4:
					if (daggerskill && daggercooldown <= 0) {
						cout << hero.name << " summon's a swarm of blades!" << endl;
						blades = rand() % 4 + 1;
						cout << blades << " blades fly at your target!" << endl;
						while (blades > 0) {
							blades--;
							herodamage = rand() % 5 + 5;
							cout << "The blade does " << herodamage * damagemult << " damage!" << endl;
						}
					}
					daggercooldown = 5;
					break;
				case 5:
					if (swordskill && swordcooldown <= 0) {
						cout << "Fury flows through "<< hero.name << "!" << endl;
						rage = true;
						ragetimer = 2;
						swordcooldown = 5;

					}
					break;
				case 6:
					if (pikeskill && pikecooldown <= 0) {
						cout << "A stunning blow does " << herodamage * damagemult << endl;
						hp -= herodamage * damagemult;
						stun = true;
						pikecooldown = 5;
					}
					break;
				default:
					cout << "Invalid input. Forcing Defend." << endl;
					defending = true;
					cout << hero.name << " defended!" << hero.name << " will take less damage this turn." << endl;
					break;


				}


				//is enemy alive
				if (hp <= 0) {
					alive = false;
					cout << "The skeleton crumbles!" << endl;
					if (hero.currentweapon != PIKE)
						hero.currentweapon = SWORD;
					swordskill = true;
					hero.potions += 2;
					cout << hero.name << " gained a sword!" << endl;
					cout << hero.name << " also gained 2 potions" << endl;
					daggercooldown--;
					swordcooldown--;
					pikecooldown--;
					cycles += 1;
					ragetimer = 0;

				}
				//enemy turn
				if (alive && stun == false) {
					cout << "The skeleton attacked" << endl;
					if (!defending) {
						hero.hp -= damage;
						cout << hero.name << " take's " << damage << " damage!" << endl;
					}
					else if (defending) {
						hero.hp -= damage / 2;
						cout << hero.name << "take's " << damage / 2 << " damage!" << endl;
					}
					daggercooldown--;
					swordcooldown--;
					pikecooldown--;
					ragetimer--;
				}
				else
					stun = false;
				spacing();
				if (hero.hp <= 0)
					lose = true;
				if (lose)
					break;
			}
		}
		if (active == DEMON) {
			opponent demon;
			int damage = demon.getenemydamage();
			int hp = demon.getenemyhealth();
			int herodamage = hero.damagedealt();
			int heal;
			int choice;
			bool rage = false;

			int blades;
			int damagemult = 1;
			cout << "A demon appears out of nowhere!" << endl;
			while (hp > 0) {
				//logic for player choice
				if (rage)
					damagemult = 2;
				else
					damagemult = 1;
				bool alive = true;
				bool defending = false;
				if (ragetimer <= 0)
					rage = false;
				cout << "What will you do" << endl;
				cout << "Remaining health: " << hero.hp << endl;
				cout << "1. Attack" << endl;
				cout << "2. Defend" << endl;
				if (hero.potions > 0) {
					cout << "3. Use health potion. Potions remaing: " << hero.potions << endl;
				}
				if (daggerskill == true) {
					if (daggercooldown <= 0) {
						cout << "4. Use dagger skill" << endl;
					}
					else {
						cout << "On cooldown for " << daggercooldown << " more turns" << endl;

					}
				}
				if (swordskill == true) {
					if (swordcooldown <= 0) {
						cout << "5. sword skill" << endl;
					}
					else {
						cout << "On cooldown for " << swordcooldown << " more turns" << endl;
					}
				}
				if (pikeskill == true) {
					if (pikecooldown <= 0) {
						cout << "5. pike skill" << endl;
					}
					else {
						cout << "On cooldown for " << pikecooldown << " more turns" << endl;
					}
				}
				cout << "To skip your turn, press anything else." << endl;
				cin >> choice;
				if (std::cin.fail())
				{
					std::cout << "That's not a valid option, forcing defend." << std::endl;
					std::cin.clear();    // clear the error
					std::cin.ignore();    // empty cin (so we forget about the bad input)
					choice = 2;
				}
				switch (choice) {
				case 1:
					hp = hp - herodamage * damagemult;
					cout << hero.name << " dealt " << herodamage * damagemult << " damage!" << endl;
					break;
				case 2:
					defending = true;
					cout << hero.name << " defended! " << hero.name << " will take less damage this turn." << endl;
					break;
				case 3:
					heal = rand() % 15 + 20;
					hero.hp += heal;
					cout << hero.name << " healed " << heal << " health!" << endl;
					if (hero.hp > 100)
						hero.hp = 100;
					hero.potions -= 1;
					break;
				case 4:
					if (daggerskill && daggercooldown <= 0) {
						cout << hero.name << " 'summon's a swarm of blades!" << endl;
						blades = rand() % 4 + 1;
						cout << blades << " blades fly at your target!" << endl;
						while (blades > 0) {
							blades--;
							herodamage = rand() % 5 + 5;
							cout << "The blade does " << herodamage * damagemult << " damage!" << endl;
						}
					}
					daggercooldown = 5;
					break;
				case 5:
					if (swordskill && swordcooldown <= 0) {
						cout << "Fury flows through " << hero.name << "!" << endl;
						rage = true;
						ragetimer = 2;
						swordcooldown = 5;

					}
					break;
				case 6:
					if (pikeskill && pikecooldown <= 0) {
						cout << "A stunning blow does " << herodamage * damagemult << endl;
						hp -= herodamage * damagemult;
						stun = true;
						pikecooldown = 5;
					}
					break;
				default:
					cout << "Invalid input. Forcing Defend." << endl;
					defending = true;
					cout << hero.name << " defended!" << hero.name << " will take less damage this turn." << endl;
					break;


				}

				//is enemy alive
				if (hp <= 0) {
					alive = false;
					cout << "The demon turns to dust!" << endl;
					hero.potions += 2;
					hero.currentweapon = PIKE;
					pikeskill = true;
					cout << hero.name << " gain's a pike!" << endl;
					cout << hero.name << " also gained 3 potions" << endl;
					daggercooldown--;
					swordcooldown--;
					pikecooldown--;
					cycles += 1;
					ragetimer = 0;


				}
				//enemy turn
				if (alive && stun == false) {
					cout << "The demon attacked" << endl;
					if (!defending) {
						hero.hp -= damage;
						cout << hero.name << " take's " << damage << " damage!" << endl;
					}
					else if (defending) {
						hero.hp -= damage / 2;
						cout << hero.name << " take's " << damage / 2 << " damage!" << endl;
					}
					daggercooldown--;
					swordcooldown--;
					pikecooldown--;
					ragetimer--;
				}

				else
					stun = false;
				spacing();
				if (hero.hp <= 0)
					lose = true;
				if (lose)
					break;

			}

		}
		if (lose)
			break;
	}
	if (lose) {
		cout << "You lost!" << endl;
		fileop("Game lost");
	}
	else {
		cout << hero.name << " managed to escape! They had " << hero.hp << " health left! Congrats!" << endl;
		fileop("Game won");
		highscorefile(logicenemy);
	}
	fileop("Game end");
}