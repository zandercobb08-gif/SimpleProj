#pragma once
#include "Utilities.h"

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
	player() { damagevalue = 1; name = "n / a"; hp = 100; }
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