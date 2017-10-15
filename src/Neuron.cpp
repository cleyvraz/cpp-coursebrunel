#include "Neuron.hpp" 
#include <cmath>

Neuron::Neuron(double m,bool r ,double sth ,double t ,double c)
:v_m_(m),refractory_(r), v_th_(sth), tau_(t),clock_(c){}

bool Neuron::update(int n,double h, double I,double R){
	
	bool spike=false;
	if(v_m_ > v_th_){
		
		spikes_time.push_back(n*h);
		++nb_spikes_;
		refractory_= true;
		spike=true;
		
	}else if((refractory_)&&((n*h)-spikes_time.back()>=1)){
			refractory_= false;
	}if(refractory_){
		v_m_=0.0;
	}else{
		double newMembPot =(exp(-h/tau_)*v_m_ + I * R *(1-exp(-h/tau_))); 
		v_m_=newMembPot;
	}
	++clock_;
	return spike;
}


void receive(double t, double j){
	
	double newMembPot =(exp(-h/tau_)*v_m_ + I * R *(1-exp(-h/tau_)))+ j; 
		v_m_=newMembPot;
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
