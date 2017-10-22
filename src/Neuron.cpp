#include "Neuron.hpp" 
#include <cmath>
#include <iostream>

Neuron::Neuron(double m=0,bool r=false,double sth=20 ,double t=2 ,double c=0,double d=15,double rcst=20,double h=0.1,double i=0.0)
:v_m_(m),refractory_(r), v_th_(sth), tau_(t),clock_(c),delay_(d),R_(rcst),h_(h),i_ext_(i)
{
	spike_buff_.resize(delay_+ 1,0.0); 
	c1=(exp(-h_/tau_));
	c2=(R_ *(1.0-c1));
}

bool Neuron::update(int n)
{
	bool spike=false;
	if(v_m_ > v_th_)
	{
		spikes_time.push_back(n*h_);
		++nb_spikes_;
		refractory_= true;
		spike=true;
		
	}else if((refractory_)&&((n*h_)-spikes_time.back()>=(1*h_)))
	{
		refractory_= false;
	}if(refractory_){
		v_m_=0.0;
	}else{
		std::cerr<< "j = " << spike_buff_[clock_%spike_buff_.size()] << std::endl;
		std::cerr<< "case buffer= " << clock_%spike_buff_.size() << std::endl;

		double newMembPot =v_m_*c1+(i_ext_*c2) + spike_buff_[clock_%spike_buff_.size()]; 
		spike_buff_[clock_%spike_buff_.size()]=0.0;		
		v_m_=newMembPot;
	}
	++clock_;		
	std::cerr<< "Clock = " << clock_ << std::endl;
	std::cerr<< "Membrane potential = " << v_m_ << std::endl;
	return spike;
}

void Neuron::receive(int t, double j)
{		
	int tStep = t % spike_buff_.size();
	spike_buff_[tStep]+=j;
	std::cerr<< "buffer à case = " << tStep<< " case actuelle= " << clock_%spike_buff_.size() << std::endl;
	std::cerr<< "futur j = " << spike_buff_[tStep] << std::endl;
}

void Neuron::setI(double i){
	
	i_ext_=i;
}

		
void Neuron::addtarget(Neuron n)
{
	targets_.push_back(n);
}

std::vector<Neuron> Neuron::gettargets()
{
	return targets_;
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
