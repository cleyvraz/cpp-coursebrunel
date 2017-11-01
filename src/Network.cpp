#include <iostream>
#include <cassert>
#include "Network.hpp"
#include "Random/Generaterandom.hpp"


Network::Network(unsigned int exci, unsigned int inhi)
:nb_excitatoryneurons_(exci),nb_inhibitoryneurons_(inhi)
{
	globalclock_= 0;
	Ce=0.1*nb_excitatoryneurons_;
	Ci=0.1*nb_inhibitoryneurons_;
	int nb_neurons =(nb_inhibitoryneurons_ + nb_excitatoryneurons_);											
	initialisation(nb_neurons);
	connect();
}


void Network::runsimulation(unsigned int n)
{
	bool spike;
	std::ofstream file("membranePotentiel.txt");
	do
	{
		for(size_t i=0; i<neurons_.size(); ++i)
		{
			spike=neurons_[i]->update();
			if(spike) 
			{
				writespikefile(file,i+1,globalclock_);
				for(size_t j=0; j<neurons_[i]->gettargetsize(); ++j)
				{	
					if((neurons_[i]->gettargets(j))<=10000)
					{
						neurons_[j]->receive(n+D_, J_);
					}else{
						neurons_[j]->receive(n+D_, J_*(-5));
					}		
				}
			}
		}
		++globalclock_;
	}while(globalclock_<n);
	file.close();
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
	unsigned int r;
	for(size_t i=0; i<neurons_.size(); ++i)
	{
		for(size_t j=0; j<=Ce; ++j)
		{
			r=generaterandom(0,(nb_excitatoryneurons_-1));
			neurons_[r]->addtarget(i);
		}	
		for(size_t n=0; n<=Ci; ++n)
		{
			if(neurons_.size()>1)
			{
				r=generaterandom(nb_excitatoryneurons_, neurons_.size()-1);
				neurons_[r]->addtarget(i);
			}
		}	
	}
}

Neuron* Network::getneuron(size_t n)
{
	return neurons_[n];
}

void Network::writespikefile(std::ofstream& m, unsigned int neuron,unsigned int t)
{
	m <<t*h_<< " " << neuron <<"\n";
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
