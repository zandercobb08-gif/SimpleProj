#include <iostream>
int powered;
int main()
{

	std::cout << "did it work" << std::endl;
	std::cout << "Close enough" << std::endl;
	std::cin >> powered;
	powered = powered + 1;
	std::cout << powered << std::endl;
	return 0;
}