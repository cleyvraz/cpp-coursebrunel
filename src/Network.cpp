#include <iostream>
#include <cassert>
#include "Network.hpp"
#include <random>

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
	size_t neurons=neurons_.size();
	Neuron* neuron;
	
	static std::random_device rd;									//I put this here so it would only be declare once
    static std::mt19937 gen(rd());
	static std::poisson_distribution<> dis(neurons_[1]->getnu_ext());  //every neuron have the same nu_ext hence the [i]
	
	do
	{
		for(size_t i=0; i<neurons; ++i)
		{
			neuron=neurons_[i];
			spike=neuron->update(dis(gen));
			if(spike) 
			{
					writespikefile(file,i+1,globalclock_);
				
				for(size_t j=0; j<(neuron->gettargetsize()); ++j)
				{	
					if((neuron->gettarget(j))<=nb_excitatoryneurons_)
					{
						neurons_[j]->receive(n+D_, J_);
					}else{
						neurons_[j]->receive(n+D_, J_*(-5));
					}		
				}
			}
		}
		++globalclock_;
	}while(globalclock_<=n);
	file.close();
}

void Network::initialisation(int nb)
{
	neurons_.resize(nb);
	for(unsigned int i=0; i<neurons_.size();i++)
	{
		Neuron* neuron=new Neuron;
		neurons_[i]=neuron;
	}
}

void Network::connect()
{
	size_t neurons=neurons_.size();
	
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> exci(0,nb_excitatoryneurons_-1);
	static std::uniform_int_distribution<> inhib(nb_excitatoryneurons_,neurons-1);
	
	for(size_t i=0; i<neurons; ++i)
	{
		for(size_t j=0; j<Ce; ++j)
		{
			neurons_[exci(gen)]->addtarget(i);
		}	
		for(size_t n=0; n<Ci; ++n)
		{
			if(neurons_.size()>1)
			{
				neurons_[inhib(gen)]->addtarget(i);
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
size_t Network::getsizeneuron()
{
	return neurons_.size();
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
