#include <iostream>
#include <cstdlib>
using namespace std;
const int player_live = 3;
const string game_title = "My game";
string playername = "Hero";
void print(string input) {
	cout << input << endl;
}

void main() {
	cout << "The title" << game_title << endl;
	cout << "Lives: " << player_live << endl;
	print("Yay");
	print(playername);
	cout << playername.length() << endl;
	cout << playername[0] << endl;
}