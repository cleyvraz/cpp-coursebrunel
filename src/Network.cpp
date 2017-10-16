#include <iostream>
#include "Network.hpp"


Network::Network(double d=15, double j=0.1)
:D_(d), J_(j){
	
	for(int i=0; i<=2;i++){
		Neuron *neuron = new Neuron;
		neurons_.push_back(*neuron);
		//neurons_[i]= new Neuron;
		//neurons_.push_back(new Neuron);
		std::cout<< "Neuron" << i << " created" << std::endl;
		}
	for(unsigned int i=0; i<=neurons_.size(); ++i){
			
		neurons_[i].targets_.push_back(neurons_[i+1]);
	}
}

void Network::connect(double n,double I){
	
	bool spike;
	for(auto& element : neurons_) {
		
		spike=element.update(n,I);
		if(spike) {
			for(auto& target : element.targets_){
				target.receive(n+D_, J_);
			}
		}
	}	
}

/*void Network::addneuron(Neuron n){
	
	neurons_.push_back(n);
}
*/

Network::~Network() {
	
	for(auto& *element : neurons_) {   
		element = nullptr;
		delete element;
    }
	
}
