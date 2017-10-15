#include <vector>


#ifndef NEURON_HPP
#define NEURON_HPP

class Neuron{

	public:
	 ///constructor & destructor
		Neuron(double m=0,bool r=false,double sth=20,double t=20,double c=0);
		~Neuron();
		
		std::vector<Neuron> targets_;			///Neurons connected to object 

	///methodes
		bool update(int,double,double,double);  ///updates neuron state from t to t+(n*h)
		int getnbSpikes();					
		double getv_m();
		bool getrefractory();
		void receive(double,double);					///receives postsynaptic current					
		
	private: 
		int nb_spikes_;
		double v_m_; 				     		///Membrane potential (in mV)
		std::vector<double> spikes_time; 		///Times when the spikes occured
		bool refractory_;
		double v_th_;							///Threshold potential 
		double tau_;							///membrane time constant
		double mem_res_;						///membrane resistance
		int clock_;
							
		
};


#endif
