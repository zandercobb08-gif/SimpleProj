#include <iostream>
#include <cstdlib>
using namespace std;
enum enemy{GOBLIN, SKELETON, DEMON};
enum weapon { CLUB, DAGGER, SWORD, PIKE};
int active;

bool daggerskill = false;
int daggercooldown = 0;
bool swordskill = false;
bool pikeskill = false;
int swordcooldown = 0;
int pikecooldown = 0;
float difmult = 1;
bool stun = false;
class player { 
public:
	int damagevalue;
	string name;
	int hp;
	int currentweapon = CLUB;
	int potions = 3;
	void getname() {
		cout << "What is this heros name?" << endl;
		cin >> name;
	}
	player() { damagevalue = 1; name = "n / a"; hp = 100;  }
	int getdamagestat(weapon active) {
		if (active == CLUB) {
			return 5;
		}
		else if (active == DAGGER) {
			daggerskill = true;
			return 8;
		}
		else if (active == SWORD) {
			swordskill = true;
			return 12;
		}
		else if (active == PIKE) {
			pikeskill = true;
			return 15;
		
		}
	}
	int damagedealt() {

		if (currentweapon == CLUB)
			damagevalue = getdamagestat(CLUB);
		else if (currentweapon == DAGGER)
			damagevalue = getdamagestat(DAGGER);
		else if (currentweapon == SWORD)
			damagevalue = getdamagestat(SWORD);
		else if (currentweapon == PIKE)
			damagevalue = getdamagestat(PIKE);
		return damagevalue;
	}
};
class opponent {
public:
	int hp;
	string name;
	int dammage;
	opponent() {
		int hp = 1;
		string name = " ";
		int dammage = 1;

	}
	int getenemyhealth() {
		int health;
		if (active == GOBLIN)
			health = 40 * difmult;
		else if (active == SKELETON)
			health = 50 * difmult;
		else if (active == DEMON)
			health = 55 * difmult;
		return health;
	}
	int getenemydamage() {
		int damage;
		if (active == GOBLIN)
			damage = 4 * difmult;
		else if (active == SKELETON)
			damage = 6 * difmult;
		else if (active == DEMON)
			damage = 10 * difmult;
		return damage;
	}
};
void spacing() {
	cout << "  " << endl;
	cout << "  " << endl;
	cout << "  " << endl;
}
int main()
{
	srand(time(NULL));
	int cycles = 0;
	int ragetimer = 0;
	int logicenemy;
	bool lose = false;
	player hero;
	hero.getname();
	if (hero.name == "Siffrid") {
		difmult = 1.2;
	}
	cout << "how many monsters stand in your way?" << endl;
	cin >> logicenemy;
	cycles = 3 - logicenemy;

	spacing();
	while (cycles < 3) {
		active = rand() % 3;
		cout << active << endl;
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
				switch (choice) {
				case 1:
					hp = hp - herodamage * damagemult;
					cout << "You dealt " << herodamage * damagemult << " damage!" << endl;
					break;
				case 2:
					defending = true;
					cout << "You defended! You will take less damage this turn." << endl;
					break;
				case 3:
					heal = rand() % 15 + 20;
					hero.hp += heal;
					cout << "You healed " << heal << " health!" << endl;
					if (hero.hp > 100)
						hero.hp = 100;
					hero.potions -= 1;
					break;
				case 4:
					if (daggerskill && daggercooldown <= 0) {
						cout << "You summon a swarm of blades!" << endl;
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
						cout << "Fury flows through you!" << endl;
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
				}


				//is enemy alive
				if (hp <= 0) {
					alive = false;
					cout << "The goblin falls!" << endl;
					if (hero.currentweapon != PIKE && hero.currentweapon != SWORD)
						hero.currentweapon = DAGGER;
					daggerskill = true;
					hero.potions += 1;
					cout << "You gained a dagger!" << endl;
					cout << "You also gained 1 potions" << endl;
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
						cout << "you take " << damage << " damage!" << endl;
					}
					else if (defending) {
						hero.hp -= damage / 2;
						cout << "you take " << damage / 2 << " damage!" << endl;
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
				switch (choice) {
				case 1:
					hp = hp - herodamage * damagemult;
					cout << "You dealt " << herodamage * damagemult << " damage!" << endl;
					break;
				case 2:
					defending = true;
					cout << "You defended! You will take less damage this turn." << endl;
					break;
				case 3:
					heal = rand() % 15 + 20;
					hero.hp += heal;
					cout << "You healed " << heal << " health!" << endl;
					if (hero.hp > 100)
						hero.hp = 100;
					hero.potions -= 1;
					break;
				case 4:
					if (daggerskill && daggercooldown <= 0) {
						cout << "You summon a swarm of blades!" << endl;
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
						cout << "Fury flows through you!" << endl;
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


				}


				//is enemy alive
				if (hp <= 0) {
					alive = false;
					cout << "The skeleton crumbles!" << endl;
					if (hero.currentweapon != PIKE)
						hero.currentweapon = SWORD;
					swordskill = true;
					hero.potions += 2;
					cout << "You gained a sword!" << endl;
					cout << "You also gained 2 potions" << endl;
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
						cout << "you take " << damage << " damage!" << endl;
					}
					else if (defending) {
						hero.hp -= damage / 2;
						cout << "you take " << damage / 2 << " damage!" << endl;
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
				cin >> choice;
				switch (choice) {
				case 1:
					hp = hp - herodamage * damagemult;
					cout << "You dealt " << herodamage * damagemult << " damage!" << endl;
					break;
				case 2:
					defending = true;
					cout << "You defended! You will take less damage this turn." << endl;
					break;
				case 3:
					heal = rand() % 15 + 20;
					hero.hp += heal;
					cout << "You healed " << heal << " health!" << endl;
					if (hero.hp > 100)
						hero.hp = 100;
					hero.potions -= 1;
					break;
				case 4:
					if (daggerskill && daggercooldown <= 0) {
						cout << "You summon a swarm of blades!" << endl;
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
						cout << "Fury flows through you!" << endl;
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

				}

				//is enemy alive
				if (hp <= 0) {
					alive = false;
					cout << "The demon turns to dust!" << endl;
					hero.potions += 2;
					hero.currentweapon = PIKE;
					pikeskill = true;
					cout << "You gain a pike!" << endl;
					cout << "You also gained 3 potions" << endl;
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
						cout << "you take " << damage << " damage!" << endl;
					}
					else if (defending) {
						hero.hp -= damage / 2;
						cout << "you take " << damage / 2 << " damage!" << endl;
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

	}
	else
		cout << "You managed to escape! You had " << hero.hp << " health left! Congrats!" << endl;

}