#include <iostream>
#include <cstdlib>
using namespace std;

struct character { string name; int hp; int level; };
struct adress { string sector; string city; };
struct player { string name; adress homeadress; int score; };
class bankaccount
{
private: 
	int balance = 20;
public:
	void deposit(int amount) {
		balance += amount;

	}
	int getbalance() {
		return balance;
	}


};

int main()
{
	
	character sif;
	sif.name = "Siffrid";
	sif.hp = 80;
	sif.level = 24;
	
	cout << sif.name << " has " << sif.hp << " hp at level " << sif.level << endl;
	
	int deposit;
	bankaccount myaccount;
	cout << "You have " << myaccount.getbalance() << " dollars in your account." << endl;
	cout << "How much would you like to deposit?" << endl;
	cin >> deposit;
	myaccount.deposit(deposit);
	cout << "You now have " << myaccount.getbalance() << " dollars in your account" << endl;

	player cor;
	cor.name = "Corleon";
	cor.homeadress.sector = "Empyrium";
	cor.homeadress.city = "Ishgard";
	cor.score = 90;

	cout << cor.name << " lives in the " << cor.homeadress.sector << " in " << cor.homeadress.city << " with a score of " << cor.score << endl;




	return 0;
}

