#include <vector>
#include "Neuron.hpp"

#ifndef NETWORK_HPP
#define NETWORK_HPP


class Network
{

	public:
		///constructor & destructor
			Network(double,double);
			~Network();
		///method
			void connect(double);
			void addneuron(Neuron);
			Neuron getneuron(int);
	private:
		int nb_neurons_=2;
		std::vector<Neuron*> neurons_;		///the network of all neurons
		double D_;							///delay in steps
		double J_; 							///amplitude/weight
};	

#endif
