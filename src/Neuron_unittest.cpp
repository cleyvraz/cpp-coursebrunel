#include "Network.hpp"
#include "gtest/gtest.h"

	/**
	 * Test 1: test if v_m after 1 step is correct
	 * /!\ CANNOT USE THIS ANYMORE SINCE THERE IS A BACKGROUND NOISE /!\ 
	 * (works if poisson is commented in the v_m_ computation)
	 *
TEST (NeuronTest, MembranePotential) 
{
		Network network(1,0);
		network.getneuron(0)->setI(1.0);
		//first update test
		network.runsimulation(1);
		EXPECT_EQ(20.0*(1.0*(1-std::exp(-0.1/20.0))), network.getneuron(0)->getv_m());
		
		network.runsimulation(10000);
		EXPECT_EQ(0, network.getneuron(0)->getnbSpikes());
}
TEST(neuronTest, externalcurrentzero)
{
		Network network(1,0);
		network.getneuron(0)->setI(0.0);
		network.runsimulation(1000);
		EXPECT_NEAR(0, network.getneuron(0)->getv_m(), 1e-4);
}
	*/


int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
