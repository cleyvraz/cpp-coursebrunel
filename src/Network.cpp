#include <iostream>
#include <cassert>
#include <string>
#include "Network.hpp"
#include <random>


Network::Network(double n,double g,unsigned int exci, unsigned int inhi)
:eta_(n),G_(g),nb_excitatoryneurons_(exci),nb_inhibitoryneurons_(inhi)
{
	globalclock_= 0;
	Ce=0.1*nb_excitatoryneurons_;
	Ci=0.1*nb_inhibitoryneurons_;
	int nb_neurons =(nb_inhibitoryneurons_ + nb_excitatoryneurons_);											
	initialization(nb_neurons);
	connect();	
}


/**************RUNSIMULATION**********************
 * Updates each neurons
 * if spike
 * 	-> send post-synapic current to targets
 *  -> writes in file (name changes depending on which graph is chosen
 * Does all of it n times
 * ***********************************************/
void Network::runsimulation(unsigned int n)
{
	bool spike;
	std::string name;
	if(G_==3) { name="SpikesA.txt";}
	if(G_==6) { name="SpikesB.txt";}
	if(G_==5) { name="SpikesC.txt";}
	if(G_==4.5) { name="SpikesD.txt";}
	std::ofstream file(name);

	size_t neurons=neurons_.size();
	Neuron* neuron;
	
	static std::random_device rd;										//I put this here so it would only be declare once (and not for each neurons)
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
					int index = neuron->gettarget(j);
					if(i<nb_excitatoryneurons_)
					{
						neurons_[index]->receive(globalclock_+D_, J_);
					}else{
						neurons_[index]->receive(globalclock_+D_, J_*(-G_));
					}		
				}
			}
		}
		++globalclock_;
	}while(globalclock_<n);
	file.close();
}


/*********INITIALIZATION**************************
 * creates a vector of size initialized in constructor of neuron pointers
 * ***********************************************/
void Network::initialization(int nb)
{
	neurons_.resize(nb);
	for(unsigned int i=0; i<neurons_.size();i++)
	{
		Neuron* neuron=new Neuron();
		neuron->seteta(eta_);
		neurons_[i]=neuron;
	}
}


/********CONNECT**************************
 * creates targets randomly
 *  ->generates 1250 incoming connections
 * 	->add target for the neurons generating that connection
 * ***********************************************/
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


/********WRITESPIKEFILE**************************
 *Writes the time at which one neuron spiked
 * I chose to only take the spikes inbetween 100ms and 300ms for the graph
 * Can be changed 
 * ***********************************************/
void Network::writespikefile(std::ofstream& m, unsigned int neuron,unsigned int t)
{
	if((t>1000)&&(t<3000)) 				
	{
		m <<t*h_<< " " << neuron <<"\n"; 
	}
} 

Neuron* Network::getneuron(size_t n)
{
	return neurons_[n];
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
