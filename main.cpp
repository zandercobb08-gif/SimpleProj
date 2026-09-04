#include <iostream>
#include <cstdlib>
using namespace std;
enum enemy{GOBLIN, SKELETON, DEMON};
enum weapon { CLUB, DAGGER, SWORD};
class player { 
public:
	string name;
	int hp;
	void getname() {
		cout << "What is this heros name?" << endl;
		cin >> name;
	}
	void takedamage(int damage) {

	}
	player() { name = "n / a"; hp = 100; }
};

int main()
{

}