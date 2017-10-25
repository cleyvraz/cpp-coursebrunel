#include <iostream>
#include "Network.hpp"
#include "Random/Random.hpp"

Network::Network(double d, double j)
:D_(d), J_(j)
{
	int nb_neurons =(nb_inhibitoryneurons_ + nb_excitatoryneurons_);											
	neurons_.resize(nb_neurons);
	connexions_.resize(nb_neurons,std::vector<int>(nb_neurons,0));										
	initialisation(nb_neurons);
	connect();
}

void Network::update(int n)
{
	bool spike;
	for(auto& element : neurons_) 
	{
		spike=element->update(n);
		if(spike) 
		{	
			for(auto& target : element->targets_)
			{
				target->receive(n+D_, J_);
			}
		}
	}	
}

void Network::initialisation(int nb)
{
	neurons_.resize(nb);

	for(unsigned int i=0; i<neurons_.size();i++)
	{
		Neuron* neuron = new Neuron;
		neurons_[i]= neuron;
	}
	
}

void Network::connect()
{
	int r;
	for(unsigned int i=0; i==neurons_.size(); ++i)
	{
		for(unsigned int j=0; j<Ce; ++j)
		{
			r=RandomGenerator(0, Ce);
			std::cout<< r << std::endl;
			connexions_[i][r]+= 1;
		}
		for(unsigned int j=0; j==Ci; ++j)
		{
			r=RandomGenerator(Ce, neurons_.size()-1);
			connexions_[i][r]+= 1;
		}
	}	
}

Neuron Network::getneuron(int n)
{
	return *neurons_[n];
}

/*void Network::addneuron(Neuron n)
{
	neurons_.push_back(n);
}
*/

Network::~Network() 
{
	
	for(auto element : neurons_) 
	{   
		delete element;
		element = nullptr;
    }
	neurons_.erase(neurons_.begin(), neurons_.end());
}
