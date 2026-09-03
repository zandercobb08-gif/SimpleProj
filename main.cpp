#include <iostream>
#include <cstdlib>

using namespace std;

int grade;
std::string password;
std::string username;
float HP;
float heat;
int weapon;
enum itemrarity {
	COMMON,
	UNCOMMON,
	RARE,
	EPIC,
	LEGENDARY
};
std::string getrarity(itemrarity rarity) {
	string readrare;
	switch (rarity) {
	case COMMON:
		readrare = "Common";
		break;
	case UNCOMMON:
		readrare = "Uncommon";
		break;
	case RARE:
		readrare = "Rare";
		break;
	case EPIC:
		readrare = "Epic";
		break;
	case LEGENDARY:
		readrare = "Legendary";
		break;

	}
	cout << readrare << endl;
	return readrare;
}
int getprice(itemrarity rarity) {
	int cost;
	switch (rarity) {
	case COMMON:
		cost = 10;
		break;
	case UNCOMMON:
		cost = 50;
		break;
	case RARE:
		cost = 200;
		break;
	case EPIC:
		cost = 1000;
		break;
	case LEGENDARY:
		cost = 5000;
		break;

	}
	return cost;
	
}
//void lockpick() 
//{
//	int guess;
//	int lock = rand() % 99;
//	bool open = false;
//	int guesses = 0;
//
//	bool unsolved = true;
//	while (!open) {
//		std::cout << "What is the keypad code? (Pick a number 1-100)" << std::endl;
//		std::cin >> guess;
//		if (guess == lock)
//			open = true;
//		else if (guess > lock)
//			std::cout << "Too high" << std::endl;
//		else if (guess < lock)
//			std::cout << "Too low" << std::endl;
//		else
//			std::cout << "Something did not work correctly, go find out what" << std::endl;
//
//
//
//	}
//
//	while (open && unsolved) {
//		unsolved = false;
//		std::cout << "You got the right code" << std::endl;
//	}
//
//
//
//
//}
//void rockmine() {
//	int stamina = 5;
//	int gathering;
//	int perception;
//	std::cout << "Whats your gathering stat?" << std::endl;
//	std::cin >> gathering;
//	std::cout << "Whats your perception stat?" << std::endl;
//	std::cin >> perception;
//	int gatherstat = gathering * 3;
//	int perceptionstat = perception * 3;
//	if (perceptionstat > 60)
//		perceptionstat = 60;
//	int minetime;
//	int restcharges = 3;
//	int gold = 0;
//	while (stamina > 0) 
//	{
//
//		std::cout << "Mine(1) or rest(2)? Rests remaining: " << restcharges << " Stamina left: " << stamina << std::endl;
//		std::cin >> minetime;
//		if (minetime == 1) {
//			int success = rand() % 99;
//			if (success > gatherstat)
//				std::cout << "You obtain nothing" << std::endl;
//			else
//				if (success <= perceptionstat) {
//					std::cout << "You obtain 2 chunks of gold" << std::endl;
//					gold = gold + 2;
//				}
//				else {
//					std::cout << "You obtain a chunk of gold" << std::endl;
//					gold++;
//				}
//			if (success <= perceptionstat / 2) {
//				std::cout << "You obtain a rest charge" << std::endl;
//				restcharges++;
//			}
//			stamina = stamina - 1;
//			
//		}
//		else if (minetime == 2) {
//			std::cout << "You rest and regain some stamina" << std::endl;
//			stamina = stamina + rand() % 4 + 1;
//			restcharges--;
//
//
//
//
//		}
//		
//	
//
//
//
//	}
//	std::cout << "You mined " << gold << " gold!" << std::endl;
//
//}
//void attacksim() {
//	for (int turncount = 0; turncount <= 5; turncount++) {
//		int crit = rand() % 5;
//		if (crit == 1)
//			std::cout << "You attacked! It was a Crit!" << std::endl;
//		else
//			std::cout << "You attacked!" << std::endl;
//
//
//
//
//	}
//}

int main()
{
	//bool playing = true;
	//int keepplaying;
	//while (playing) 
	//{
	//	int game;
	//	std::cout << "Choose which program to run" << std::endl;
	//	std::cout << "press 1 to play the attack simulator" << std::endl;
	//	std::cout << "press 2 to play the mining simulator" << std::endl;
	//	std::cout << "press 3 to play the lockpicking game" << std::endl;
	//	std::cin >> game;
	//	if (game == 1)
	//		attacksim();
	//	else if (game == 2)
	//		rockmine();
	//	else if (game == 3)
	//		lockpick();
	//	else
	//		std::cout << "That is an invalid game" << std::endl;
	//	std::cout << "Play another game? 1 for y or 2 for n" << std::endl;
	//	std::cin >> keepplaying;
	//	if (keepplaying == 1) {
	//		std::cout << "OK" << std::endl;
	//		game = 0;
	//	}
	//	else if (keepplaying == 2) {
	//		std::cout << "OK, have a nice day" << std::endl;
	//		playing = false;
	//	}
	//	else
	//		break;
	//	
	//	
	//}
	int rare;
	string rarity;
	int price;
	cout << "Choose a rarity" << endl;
	cout << "Common = 0" << endl;
	cout << "Uncommon = 1" << endl;
	cout << "Rare = 2" << endl;
	cout << "Epic = 3" << endl;
	cout << "Legendary = 4" << endl;
	cin >> rare;
	if (rare == 0){
		rarity = getrarity(COMMON);
		price = getprice(COMMON);
	}
	else if (rare == 1) {
		rarity = getrarity(UNCOMMON);
		price = getprice(UNCOMMON);
	}
	else if (rare == 2) {
		rarity = getrarity(RARE);
		price = getprice(RARE);
	}
	else if (rare == 3) {
		rarity = getrarity(EPIC);
		price = getprice(EPIC);
	}
	else if (rare == 4) {
		rarity = getrarity(LEGENDARY);
		price = getprice(LEGENDARY);
		
}
	int sell = price/2;
	cout << "A " << rarity << " rarity item will cost " << price << " gold." << endl;
	cout << "If you have an item of said rarity, we will buy it off of you for " << sell << " gold" << endl;
	return 0;
}


//void weapon_selection(weapons weapon) {
//
//
//	switch (weapon)
//	{
//	case Sword:
//		std::cout << "It deals 8 damage" << std::endl;
//		break;
//	case Greatsword:
//		std::cout << "It deals 12 damage" << std::endl;
//		break;
//	case Spear:
//		std::cout << "It deals 10 damage" << std::endl;
//		break;
//	case GreatClub:
//		std::cout << "It deals 15 damage" << std::endl;
//		break;
//	case Dagger:
//		std::cout << "It deals 5 damage" << std::endl;
//		break;
//	default:
//		break;
//	}
//}





















/*std::cout << "What's your grade?" << std::endl;
std::cin >> grade;
std::cout << grade << std::endl;
if (grade > 100)
	std::cout << "That's not possible" << std::endl;
else if (grade >= 90)
	std::cout << "An A" << std::endl;
else if (grade >= 80)
	std::cout << "A B" << std::endl;
else if (grade >= 70)
	std::cout << "A C" << std::endl;
else if (grade >= 60)
	std::cout << "A D" << std::endl;
else if (grade < 60 && grade >= 0)
	std::cout << "An F" << std::endl;
else
	std::cout << "Thats not a valid score" << std::endl;


std::cout << "Give me a whole number" << std::endl;
std::cin >> grade;
if (grade == 0)
	std::cout << "You chose 0 of all numbers" << std::endl;
else if (grade % 2 == 1)
	std::cout << "An odd number" << std::endl;
else
	std::cout << "an even number" << std::endl;

std::cout << "Username" << std::endl;
std::cin >> username;
std::cout << "password" << std::endl;
std::cin >> password;

if (username == "hello" && password == "1234")
	std::cout << "access granted" << std::endl;
else
	std::cout << "access denied" << std::endl;

std::cout << "Give me a health percentage" << std::endl;
std::cin >> HP;

if (HP >= 75)
	std::cout << "You don't need healing" << std::endl;
else if (HP >= 50)
	std::cout << "You should take a small health potion" << std::endl;
else if (HP >= 0)
	std::cout << "you should use a larger health potion" << std::endl;
else
	std::cout << "Your out of HP" << std::endl;

std::cout << "how hot is it today" << std::endl;
std::cin >> heat;
if (heat >= 80)
	std::cout << "A pair of shorts and a tshirt should work" << std::endl;
else if (heat >= 60)
	std::cout << "A long sleeve shirt and some jeans sound nice" << std::endl;
else if (heat >= 32)
	std::cout << "you should were something pretty warm" << std::endl;
else
	std::cout << "You need a thick jacket today" << std::endl;
return 0;*/

