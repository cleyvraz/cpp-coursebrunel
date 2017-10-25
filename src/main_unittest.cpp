#include <iostream> 
#include "Neuron.cpp"
#include "Network.cpp"
#include "gtest/gtest.h"

TEST (NeuronTest, MembranePotential)
{
		Neuron neuron;
		neuron.setI(1.0);
		
		//first update test
		neuron.update(1);
		EXPECT_EQ(20.0*(1.0*(1-std::exp(-0.1/20.0))), neuron.getv_m());
}

/*
TEST(NetworkTest, Connexions)
{
	Network network;
	
	int n;
	size_t c=network.connexions_.size();
	for(unsigned int i=0; i<c; ++i)
	{
		for(unsigned int j=0; j<c; ++j)
		{
			if(network.connexions_[i][j] != 0)
			{
				++n;
			}		
		}	
	}
	EXPECT_EQ( 1250, n);
	
}*/

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
