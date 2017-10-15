#include <vector>
#include "Neuron.hpp"



#ifndef NETWORK_HPP
#define NETWORK_HPP


class Network{

	public:
		///constructor & destructor
			Network(double d=1.5,double j=0.1);
			~Network();
		///method
			void connect(double,double,double,double);
	
	private:
		std::vector<Neuron> neurons_;
		double D_;							///delay
		double J_; 						///amplitude/weight
};

#endif
