#include <iostream>
#include "Network.hpp"


Network::Network(double d, double j)
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

void connect(double n,double h, double I, double R){
	
	bool spike;
	for(auto& element : neurons_) {
		
		spike=element.update(n,h,I,R);
		if(spike) {
		
			for(auto& target : element.targets_){
				
				target.receive(n*h +D_, J_);
			}
		}
	}	
}



Network::~Network() {
	
	for(auto& element : neurons_) {
        delete element;
        element = nullptr;
    }
	
}
