#include "Random.hpp"

/*std::mt19937& Random::RandomGenerator(int min,int max)
{
	static bool initialise = true;
	if(initialise) 
	{
		strand(time(NULL));
		first=false;
	}
	return min+rand() % ( max-min);
}*/

int RandomGenerator(int min,int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min,max);
	return dis(gen);
}
