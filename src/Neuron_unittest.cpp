#include "Network.hpp"
#include "gtest/gtest.h"
	 
TEST (NeuronTest, MembranePotential) //!<test if v_m after 1 step is correct
{
		Neuron neuron;
		neuron.setI(1.0);
		//!!<first update test
		neuron.update(0);
		EXPECT_EQ(20.0*(1.0*(1-std::exp(-0.1/20.0))),neuron.getv_m());
		
		for(int i=0; i<10000 ; ++i)
		{
			neuron.update(0);
		}
		EXPECT_EQ(0, neuron.getnbSpikes());
}

TEST(neuronTest, externalcurrentzero)
{
		Neuron neuron;
		neuron.setI(0.0);
		for(int i=0; i<10000 ; ++i)
		{
			neuron.update(0);
		}
		EXPECT_NEAR(0, neuron.getv_m(), 1e-4);
}

TEST(neurontest,spiketimes)
{
	//!<A single neuron with an external current of 1.01 will spike at time 92.4ms, 186.8ms, 281.2ms,375.6 ms etc..
	Neuron neuron;
	neuron.setI(1.01);
	for(int i=0; i<924 ; ++i) //!<first spike at time 92.4 (924 steps)
	{
		neuron.update(0);
	}
	EXPECT_EQ(0,neuron.getnbSpikes());
	neuron.update(0);
	EXPECT_EQ(1,neuron.getnbSpikes());
	EXPECT_EQ(0.0,neuron.getv_m());
	
	for(int j=0; j<943 ; ++j) //!<second spike at time 925+943= 1868 steps
	{
		neuron.update(0);
	}
	EXPECT_EQ(1, neuron.getnbSpikes());
	neuron.update(0);
	EXPECT_EQ(2, neuron.getnbSpikes());
}

TEST(NetworkTest,numberconnections)
{
	Network network(40,10);
	int connections=0;
	for(int i=0; i<50; ++i)
	{
		connections+=network.getneuron(i)->gettargetsize();
	}
	EXPECT_EQ(50*5,connections);
}

TEST(Networktest, numberneuron )
{
	Network network;
	EXPECT_EQ(12500 ,network.getsizeneuron());
	Network net(100,392);
	EXPECT_EQ(492 ,net.getsizeneuron());
}

TEST(Networktest, numberUpdate)
{
	Network network;
	network.runsimulation(100);
	EXPECT_EQ(100,(network.getneuron(1)->getclock()));

}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
