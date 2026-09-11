#pragma once
#include "Utilities.h"
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