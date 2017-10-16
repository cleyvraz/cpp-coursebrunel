#include <vector>
#include "Neuron.hpp"

#ifndef NETWORK_HPP
#define NETWORK_HPP


class Network{

	public:
		///constructor & destructor
			Network(double,double);
			~Network();
		///method
			void connect(double,double);
			void addneuron(Neuron);
	private:
		std::vector<Neuron> neurons_;		///the network of all neurons
		double D_;							///delay in steps
		double J_; 							///amplitude/weight
};	

#endif
