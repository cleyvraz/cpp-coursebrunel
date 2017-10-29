#include <iostream>
#include <random>
#include "Random.hpp"
#include "Random.cpp"

using namespace std;

int main(){
	int number;
	default_random_engine generator;
	for(int i=0; i<=100; ++i)
	{
		uniform_int_distribution<int> distribution(0,1000);
  		number = distribution(generator);
		cout<< i << " : " << number << endl;
		number = RandomGenerator(0,1000);
		cout<< i << " (2): " << number << endl;

	}
	
	
return 0;

}
