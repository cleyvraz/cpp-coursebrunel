#include <vector>
#include "Neuron.hpp"


#ifndef NETWORK_HPP
#define NETWORK_HPP


class Network
{
	public:
	///constructor & destructor
		Network(double d=15, double j=0.1);
		~Network();
	///method
		void update(int);
		void addneuron(Neuron);
		Neuron getneuron(int);
		std::vector<std::vector<int>> connexions_; // en public pour main_unittest accès

	private:
		//int nb_neurons_=2;
		unsigned int nb_excitatoryneurons_=10000;
		unsigned int nb_inhibitoryneurons_=2500;
		unsigned int Ce=1000;
		unsigned int Ci=250;
		std::vector<Neuron*> neurons_;		///the network of all neurons
		double D_;							///delay in steps
		double J_; 							///amplitude/weight
		void initialisation(int);				/*! Initialize neurons_*/
		void connect(); 						/*! Initialize the connexions*/
		void writespikefile();					/*! write the spike time in a file */
};	

#endif
