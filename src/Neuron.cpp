#include "Neuron.hpp" 
#include <cmath>
#include <iostream>

Neuron::Neuron(double m=0,bool r=false,double sth=20 ,double t=20 ,double c=0,double d=1.5,double rcst=20,double h=0.1)
:v_m_(m),refractory_(r), v_th_(sth), tau_(t),clock_(c),delay_(d),R_(rcst),h_(h)
{
	
	c1=(exp(-h/tau_)*v_m_);
	c2= R_ *(1-exp(-h/tau_));

}

bool Neuron::update(int n, double I)
{
	
	bool spike=false;
	if(v_m_ > v_th_){
		
		spikes_time.push_back(n*h_);
		++nb_spikes_;
		refractory_= true;
		spike=true;
		
	}else if((refractory_)&&((n*h_)-spikes_time.back()>=1)){
			refractory_= false;
	}if(refractory_){
		v_m_=0.0;
	}else{
		double newMembPot =c1+I*c2; //addition du j!
		v_m_=newMembPot;
	}
	++clock_;
	return spike;
}


void Neuron::receive(int t, double j)
{		
	int tStep = t % spike_buff_.size();
	spike_buff_[tStep]+=j;
}

int Neuron::getnbSpikes()
{
	
	return nb_spikes_;
}

double Neuron::getv_m()
{
	
	return v_m_;
}

bool Neuron::getrefractory()
{
	
	return refractory_;
}

double Neuron::geth()
{
	
	return h_;	
}
Neuron::~Neuron(){}
