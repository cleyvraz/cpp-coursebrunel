#include "Generaterandom.hpp"
#include <cassert>
unsigned int generaterandom(unsigned int min,unsigned int max)
{	
	unsigned int number;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min,max);
	number=dis(gen);
	assert(number<=max);
	assert(number>=min);
	return number;
}
