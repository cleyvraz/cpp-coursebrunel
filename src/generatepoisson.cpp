#include "Generatepoisson.hpp"


#include <iostream>


double generatepoisson(double rate)
{
	int number;
	std::default_random_engine gen;
	std::poisson_distribution<int> dis(rate);
	number=dis(gen);
	std::cout<< "poisson : " << number<< std::endl;
	return number;
}
