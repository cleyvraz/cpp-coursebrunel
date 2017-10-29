#include "Generatepoisson.hpp"


double generatepoisson(double rate)
{
	double number;
	std::default_random_engine gen;
	std::poisson_distribution<int> dis(rate);
	number=dis(gen);
	return number;
}
