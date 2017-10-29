#include "Generaterandom.hpp"

int generaterandom(int min,int max)
{	
	int number;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min,max);
	number=dis(gen);
	return number;
}
