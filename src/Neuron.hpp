#include <vector>

#ifndef NEURON_HPP
#define NEURON_HPP

class Neuron
{
	public:
		Neuron();									//!<constructor(initialization of some members in the core)
		~Neuron();									//!<destructor
		bool update(int);  							//!<updates neuron state from t to t+h : takes an int which is the poisson variable
		void receive(int,double);					//!<receives postsynaptic current (time t+d, weight J)					
		int getnbSpikes();							//!<getter for the total number of spikes	
		double getv_m();							//!<getter for the membrane potential 
		bool getrefractory();						//!<getter for the state of the neuron
		double geth();								//!<getter for h_, the integration time step
		void setI(double);							//!<setter for the external current I
		unsigned int gettargetsize();				//!<getter for the size of the vector of targets(neurons which receive the postsynaptic current
		unsigned int gettarget(unsigned int);		//!<getter for the index of one target neuron
		double getnu_ext();							//!<getter for nu_ext
		void addtarget(unsigned int i);				//!<adds an index of a target neuron

	private: 
		const double v_th_=20;						//!<Threshold potential
		const double tau_=20;						//!<Membrane time constant
		const double R_=20;							//!<Membrane resistance
		const double h_=0.1;						//!<Integration time step
		const double delay_=15;						//!<Delay (in steps!) 
		const double j_ext=0.1;						//!<Spike response amplitude
		double eta;									//
		int nb_spikes_;								//!<Total nb of spikes 
		double v_m_; 				     			//!<Membrane potential (in mV)
		bool refractory_;							//!<State of the neuron (refractory for a small time after a spike)
		int clock_;									//!<Clock of the neuron
		double c1;									//!<constant for the solution of the differential equation
		double c2;									//!<constant for the solution of the differential equation
		double i_ext_;								//!<external courant (typically=0, can be changed with the setter)
		double nu_ext_;								//!<The rate which is used for the poisson distribution (background noise)
		std::vector<double> spikes_time; 			//!<Stores the time when spikes occure
		std::vector<double> spike_buff_;			//!<Ring buffer: used to contain amplitude J received from other neurons
		std::vector<unsigned int> targets_;			//!<Neurons connected to object 

};

#endif
