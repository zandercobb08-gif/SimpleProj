#pragma once
#include <iostream>
#include "Stringutils.h"

using namespace std;
enum enemy { GOBLIN, SKELETON, DEMON };
enum weapon { CLUB, DAGGER, SWORD, PIKE };
int active;

bool daggerskill = false;
int daggercooldown = 0;
bool swordskill = false;
bool pikeskill = false;
int swordcooldown = 0;
int pikecooldown = 0;
float difmult = 1;
bool stun = false;

