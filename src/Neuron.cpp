#include "Neuron.hpp" 
#include <cmath>


Neuron::Neuron(double m=0, bool r=(false), double sth=20, double t=20,double c=0)
:v_m_(m),refractory_(r), v_th_(sth), tau_(t),clock_(c){
}

void Neuron::update(int n,double h, double I,double R){

	
	if(v_m_ > v_th_){
		
		spikes_time.push_back(n*h);
		nb_spikes_ ++;
		refractory_= true;
	}else if((refractory_)&&(spikes_time.back()+2.0*h >=n*h)){
			refractory_= false;
	}if(refractory_){
		
		v_m_=0.0;
	}else{
		double newMembPot =(exp(-h/tau_)*v_m_ + I * R *(1-exp(-h/tau_))); 
		v_m_=newMembPot;
	}
	
}

int Neuron::getnbSpikes(){
	
	return nb_spikes_;
}

double Neuron::getv_m(){
	
	return v_m_;
}

bool Neuron::getrefractory(){
	
	return refractory_;
}


Neuron::~Neuron(){}
