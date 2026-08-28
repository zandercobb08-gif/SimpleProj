#include <iostream>
int grade;
std::string password;
std::string username;
float HP;
float heat;
int main()
{


	//std::cout << "What's your grade?" << std::endl;
	//std::cin >> grade;
	//std::cout << grade << std::endl;
	//if (grade >= 90)
	//	std::cout << "An A" << std::endl;
	//else if (grade >= 80)
	//	std::cout << "A B" << std::endl;
	//else if (grade >= 70)
	//	std::cout << "A C" << std::endl;
	//else if (grade >= 60)
	//	std::cout << "A D" << std::endl;
	//else if (grade < 60)
	//	std::cout << "An F" << std::endl;
	//else
	//	std::cout << "Thats not a valid score" << std::endl;


	//std::cout << "Give me a whole number" << std::endl;
	//std::cin >> grade;
	//if (grade == 0)
	//	std::cout << "You chose 0 of all numbers" << std::endl;
	//else if (grade % 2 == 1)
	//	std::cout << "An odd number" << std::endl;
	//else
	//	std::cout << "an even number" << std::endl;

	std::cout << "Username" << std::endl;
	std::cin >> username;
	std::cout << "password" << std::endl;
	std::cin >> password;

	if (username == "hello" && password == "1234")
		std::cout << "access granted" << std::endl;
	else
		std::cout << "access denied" << std::endl;

	//std::cout << "Give me a health percentage" << std::endl;
	//std::cin >> HP;

	//if (HP >= 75)
	//	std::cout << "You don't need healing" << std::endl;
	//else if (HP >= 50)
	//	std::cout << "You should take a small health potion" << std::endl;
	//else if (HP >= 0)
	//	std::cout << "you should use a larger health potion" << std::endl;
	//else
	//	std::cout << "Your out of HP" << std::endl;

	//std::cout << "how hot is it today" << std::endl;
	//std::cin >> heat;
	//if (heat >= 80)
	//	std::cout << "A pair of shorts and a tshirt should work" << std::endl;
	//else if (heat >= 60)
	//	std::cout << "A long sleeve shirt and some jeans sound nice" << std::endl;
	//else if (heat >= 32)
	//	std::cout << "you should were something pretty warm" << std::endl;
	//else
	//	std::cout << "You need a thick jacket today" << std::endl;
	//return 0;
}