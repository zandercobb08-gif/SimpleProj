#include <iostream>
#include <cstdlib>
using namespace std;
enum enemy{GOBLIN, SKELETON, DEMON};
int active = GOBLIN;
enum weapon { CLUB, DAGGER, SWORD};

bool daggerskill = false;
int daggercooldown = 0;
bool swordskill = false;
int swordcooldown = 0;

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
	void takedamage(int damage) {

	}
	player() { damagevalue = 1; name = "n / a"; hp = 100;  }
	int getdamagestat(weapon active) {
		if (active == CLUB) {
			return 5;
		}
		else if (active == DAGGER) {
			daggerskill = true;
			return 7;
		}
		else if (active == SWORD) {
			swordskill = true;
			return 10;
		}
	}
	int damagedealt() {

		if (currentweapon == CLUB)
			damagevalue = getdamagestat(CLUB);
		else if (currentweapon == DAGGER)
			damagevalue = getdamagestat(DAGGER);
		else if (currentweapon == SWORD)
			damagevalue = getdamagestat(SWORD);
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
			health = 30;
		else if (active == SKELETON)
			health = 40;
		else if (active == DEMON)
			health = 60;
		return health;
	}
	int getenemydamage() {
		int damage;
		if (active == GOBLIN)
			damage = 3;
		else if (active == SKELETON)
			damage = 5;
		else if (active == DEMON)
			damage = 8;
		return damage;
	}
};

int main()
{
	int cycles = 0;
	player hero;
	hero.getname();

	while (cycles < 3) {
		if (active == GOBLIN) {
			opponent goblin;
			int damage = goblin.getenemydamage();
			int hp = goblin.getenemyhealth();
			int herodamage = hero.damagedealt();
			int heal;
			int choice;
			cout << "A crazed goblin stands in your way!" << endl;
			while (hp > 0) {
				bool alive = true;
				bool defending = false;
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
					hp = hp - herodamage;
					cout << "You dealt " << herodamage << " damage!" << endl;
					break;
				case 2:
					defending = true;
					cout << "You defended! You will take less damage this turn." << endl;
					break;
				case 3:
					heal = rand() % 10 + 10;
					hero.hp += heal;
					cout << "You healed " << heal << " health!" << endl;
					hero.potions -= 1;
					break;
				}
				if (hp >! 0) {
						alive = false;
						cout << "The goblin is slain!" << endl;
						hero.currentweapon = DAGGER;
						daggerskill = true;
						hero.potions += 1;
						cout << "You gained a dagger!" << endl;
						cout << "You also gained 1 potion" << endl;

				}

				}

			}


		}
	
}