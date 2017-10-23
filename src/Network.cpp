#include <iostream>
#include "Network.hpp"

Network::Network(double d, double j)
:D_(d), J_(j)
{

	neurons_.resize(nb_neurons_);
	//neurons_.resize(nb_inhibitoryneurons_+ nb_excitatoryneurons_);

	for(int i=0; i<nb_neurons_;i++)
	{
		Neuron* neuron = new Neuron;
		neurons_[i]= neuron;
	}
	/*for(int i=0; i<nb_inhibitoryneurons_;i++)
	{
		InhibitoryNeuron* neuron = new InhibitoryNeuron;
		neurons_[i]= neuron;
	}
	for(int i=0; i<nb_excitatoryneurons_;i++)
	{
		ExcitatoryNeuron* neuron = new ExcitatoryNeuron;
		neurons_[i]= neuron;
	}
	*/
	neurons_[0]->addtarget((neurons_[1]));
	neurons_[0]->setI(1.01);
	/*for(unsigned int i=0; i<1; ++i){  //boucle pas encore définie pour plusieurs neurones
		std::cerr<< "boucle for " << i<< std::endl;
		neurons_[i]->addtarget(*(neurons_[i+1]));
	}*/
}

void Network::connect(double n)
{
	bool spike;
	for(int i=0; i<neurons_.size(); ++i)
	//for(auto& element : neurons_) 
	{
		//spike=element->update(n);
		std::cerr<< i;
		spike=neurons_[i]->update(n);
		if(spike) 
		{	
			std::cerr<<"Neuron " << i << " SPIKE!! "<< std::endl;
			
			//std::vector<Neuron> v=element->gettargets();
			//for(j=0; j<gettargets().size() ; ++j)
			//for(auto& target : element->targets_)
			for(auto& target : neurons_[i]->targets_)
			{
			
				target->receive(n+D_, J_);
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
