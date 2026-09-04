#include <iostream>
#include <cstdlib>
using namespace std;
enum enemy{GOBLIN, SKELETON, DEMON};
enum weapon { CLUB, DAGGER, SWORD};
bool daggerskill = false;
bool swordskill = false;
class player { 
public:
	int damagevalue;
	string name;
	int hp;
	int currentweapon = CLUB;
	void getname() {
		cout << "What is this heros name?" << endl;
		cin >> name;
	}
	void takedamage(int damage) {

	}
	player() { name = "n / a"; hp = 100;}
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
		cout << "damage you will deal: " << damagevalue << endl;
		return damagevalue;
	}
};

int main()
{

	player hero;
	hero.getname();
	cout << "You chose " << hero.name << endl;
	hero.damagedealt();
}