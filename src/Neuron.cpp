#include "Neuron.hpp" 
#include <cmath>
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
}


/******UPDATE********************************************
 * Update the state at each steps. 
 * Checks if the potential is higher than threshold potential (if yes->potential =0)
 * Checks if in refractory -> does nothing
 * Computes the membrane potential
 * ******************************************************/
bool Neuron::update(int poisson)
{
	bool spike=false;
	int index=clock_%spike_buff_.size();
	if(v_m_ > v_th_)
	{
		tspike_=clock_;
		++nb_spikes_;
		refractory_= true;
		spike=true;
		v_m_=0.0;

	}else if((clock_)-(tspike_)>(tRef_))
	{
		refractory_= false;
	}
	if(!refractory_)
	{
		v_m_= v_m_*c1+(i_ext_*c2)+spike_buff_[index]+ j_ext*poisson;
	}
	spike_buff_[index]=0.0;	
	++clock_;		
	return spike;
}


/******************RECEIVE************************
 * Uses a ring buffer to store the post-synaptical current given by
 * another neuron
 *************************************************/
void Neuron::receive(int t, double j)
{		
	int tStep = t % spike_buff_.size();
	spike_buff_[tStep]+=j;
}


/*************************************************
 *			SETTERS & GETTERS (mostly used in tests)
 *************************************************/
void Neuron::setI(double i)
{
	i_ext_=i;
}
/**************SETETA******************************
 *seteta is called by network. Chose it to be done by setter and not in
 *constructor so neuron constructor wouldn't take any argument which would
 * have made tests more complicated
 * ************************************************/	
void Neuron::seteta(double e)
{
	eta_=e;
	assert(eta_!=0.0);
	nu_ext_=(eta_*v_th_*h_/(j_ext*tau_));
}
double Neuron::getbuffer(unsigned int c)
{
	return spike_buff_[c];
}
unsigned int Neuron::gettargetsize()
{
	return targets_.size();
}

unsigned int Neuron::gettarget(unsigned int i)
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

unsigned int Neuron::getclock()
{
	return clock_;
}

bool Neuron::getrefractory()
{
	return refractory_;
}

double Neuron::getnu_ext()
{
	return nu_ext_;
}

double Neuron::geth()
{
	return h_;	
}
Neuron::~Neuron(){}
