#include <vector>
#include "Neuron.hpp"
#include "InhibitoryNeuron.hpp"
#include "ExcitatoryNeuron.hpp"

#ifndef NETWORK_HPP
#define NETWORK_HPP


class Network
{
	public:
	///constructor & destructor
		Network(double d=15, double j=0.1);
		~Network();
	///method
		void connect(double);
		void addneuron(Neuron);
		Neuron getneuron(int);
	private:
		int nb_neurons_=2;
		//int nb_inhibitoryneurons_=2500;
		//int nb_excitatoryneurons_=10000;
		std::vector<Neuron*> neurons_;		///the network of all neurons
		double D_;							///delay in steps
		double J_; 							///amplitude/weight
};	

#endif
