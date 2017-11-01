#include "Generatepoisson.hpp"

double generatepoisson(double rate)
{
	double number;
	std::random_device rd;
    std::mt19937 gen(rd());
	std::poisson_distribution<> dis(rate);
	number=dis(gen);
	return number;
}
