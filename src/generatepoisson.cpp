#include "Generatepoisson.hpp"


int generatepoisson(int rate)
{
	int number;
	std::default_random_engine gen;
	std::poisson_distribution<int> dis(rate);
	number=dis(gen);
	return number;
}
