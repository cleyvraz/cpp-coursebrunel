#include "Neuron.hpp" 
#include "Random/Generatepoisson.hpp"
#include <cmath>
#include <iostream>
#include <cassert>

Neuron::Neuron()
{	
	nb_spikes_=0;
	v_m_=0;
	refractory_=false;
	clock_=0;
	i_ext_=0;
	spike_buff_.resize(delay_+ 1,0.0); 
	c1=(exp(-h_/tau_));
	c2=(R_*(1.0-c1));
	nu_ext_=(2*v_th_*h_/(j_ext*tau_));
}

bool Neuron::update()
{
	bool spike=false;
	if(v_m_ > v_th_)
	{
		spikes_time.push_back(clock_*h_);
		++nb_spikes_;
		refractory_= true;
		spike=true;
	}else if((refractory_)&&((clock_)-(spikes_time.back()/h_)>=(20)))
	{
		refractory_= false;
	}
	if(refractory_){
		v_m_=0.0;
	}else
	{
		double newMembPot =v_m_*c1+(i_ext_*c2) + spike_buff_[clock_%spike_buff_.size()] + generatepoisson(nu_ext_); 
		spike_buff_[clock_%spike_buff_.size()]=0.0;		
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

void Neuron::setI(double i)
{
	i_ext_=i;
}

unsigned int Neuron::gettargetsize()
{
	return targets_.size();
}

unsigned int Neuron::gettargets(unsigned int i)
{
	return targets_[i];
}

void Neuron::addtarget(unsigned int i)
{
	targets_.push_back(i);
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
