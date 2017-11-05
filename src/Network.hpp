#include <vector>
#include <fstream>
#include <iostream>
#include "Neuron.hpp"

#ifndef NETWORK_HPP
#define NETWORK_HPP

class Network
{
	public:
		Network(double n=2,double g=5,unsigned int exci=10000, unsigned int inhi=2500);		//!<Constuctor (possibility of changes nb of neurons -> used in the tests)
		~Network();																			//!<Destructor (destroys all the pointers)
		void runsimulation(unsigned int);													//!<Runs the simultation, calls update method of calss neuron
		Neuron* getneuron(size_t);															//!<Getter of a neuron from the vector neuron_ (used in tests)
		size_t getsizeneuron();																//!<Getter number of all neurons
	
	private:
		constexpr static  double h_= 0.1;													//!<integration time step
		constexpr static  double D_=15;														//!<delay (in steps!)
		constexpr static  double J_=0.1;													//!<spike response amplitude
		double G_;																			//!Needed to compute weight of inhibitory neurons (J*(-G))
		double eta_;																		//!external rate divided by threshold rate
		unsigned int globalclock_;															//!<Global clock (incremented once each neurons' clock has been incremented
		unsigned int nb_excitatoryneurons_;													
		unsigned int nb_inhibitoryneurons_;
		unsigned int Ce;																	//!<Excitatory connections (10% of all the excitatory neurons)
		unsigned int Ci;																	//!<Inhibitory connections (10% of all the inhibitory neurons)
		std::vector<Neuron*> neurons_;														//!<the network of all neurons
					
		void initialization(int);															//!<Initialize neurons_
		void connect(); 																	//!<Initialize the connexions
		void writespikefile(std::ofstream&,unsigned int,unsigned int);						//!<Writes which neuron spikes at which time (used for the graphs)
};	

#endif
