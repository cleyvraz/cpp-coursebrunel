#include <iostream>
#include "Network.hpp"
#include "GenerateRandom.hpp"

Network::Network(double d, double j)
:D_(d), J_(j)
{	
	std::cout<< "debut init" << std::endl;

	int nb_neurons =(nb_inhibitoryneurons_ + nb_excitatoryneurons_);											
	neurons_.resize(nb_neurons);
	connexions_.resize(nb_neurons,std::vector<int>(nb_neurons,0));										
	initialisation(nb_neurons);
	connect();
		std::cout<< "fin init" << std::endl;

}

void Network::update(int n)
{
	bool spike;
	for(int i=0; i<neurons_.size(); ++i)
	{
		spike=neurons_[i]->update(n);
		if(spike) 
		{	
			for(int j=0; j<neurons_.size(); ++j)
			{
				if(connexions_[j][i] != 0)
				{	
					neurons_[j]->receive(n+D_, J_);
				}
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
	for(unsigned int i=0; i<neurons_.size(); ++i)
	{
		for(unsigned int j=0; j<Ce; ++j)
		{
			r=generaterandom(0, Ce);
			connexions_[i][r]+= 1;
		}
		for(unsigned int n=0; n<=Ci; ++n)
		{					
			r=generaterandom(Ce, neurons_.size()-1);
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
void Network::writespikefile()
{
	
	
	
	
} 

Network::~Network() 
{
	
	for(auto element : neurons_) 
	{   
		delete element;
		element = nullptr;
    }
	neurons_.erase(neurons_.begin(), neurons_.end());
}
