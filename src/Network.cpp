#include <iostream>
#include <cassert>
#include "Network.hpp"
#include "Generaterandom.hpp"

Network::Network(double d, double j)
:D_(d), J_(j)
{	
	std::cout<< "debut init" << std::endl;
	int nb_neurons =(nb_inhibitoryneurons_ + nb_excitatoryneurons_);											
	neurons_.resize(nb_neurons);
	initialisation(nb_neurons);
	connect();

	std::cout<< "fin init" << std::endl;
}

void Network::update(unsigned int n,std::ofstream& file)
{
	bool spike;
	for(size_t i=0; i<neurons_.size(); ++i)
	{
		spike=neurons_[i]->update(n);
		if(spike) 
		{
			writespikefile(file,i+1,n);
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
			r=generaterandom(nb_excitatoryneurons_, neurons_.size()-1);
			neurons_[r]->addtarget(i);
		}	
	}
}

Neuron Network::getneuron(int n)
{
	return *neurons_[n];
}

double Network::getj()
{
	return J_;
}

void Network::writespikefile(std::ofstream& m, unsigned int neuron,unsigned int t)
{
	m <<t*h_ << " " << neuron <<"\n";
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
