#include <iostream>
#include "Network.hpp"

Network::Network(double d=15, double j=0.1)
:D_(d), J_(j)
{

	neurons_.resize(nb_neurons_);
	std::cerr<< neurons_.size()<<","<< nb_neurons_<< std::endl;

	for(int i=0; i<nb_neurons_;i++){
		Neuron* neuron = new Neuron;
		neurons_[i]= neuron;
	}
	
	neurons_[0]->addtarget(*(neurons_[1]));
	neurons_[0]->setI(1.01);
	/*for(unsigned int i=0; i<1; ++i){  //boucle pas encore définie pour plusieurs neurones
		std::cerr<< "boucle for " << i<< std::endl;
		neurons_[i]->addtarget(*(neurons_[i+1]));
	}*/
}

void Network::connect(double n)
{
	bool spike;
	for(auto& element : neurons_) 
	{
		spike=element->update(n);
		if(spike) 
		{	
			std::cerr<<"SPIKE!! "<< element << std::endl;
			
			//std::vector<Neuron> v=element->gettargets();
			
			for(auto& target : element->targets_)
			{
				target.receive(n+D_, J_);
			}
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
