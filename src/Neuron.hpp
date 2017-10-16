#include <vector>
#include <array>


#ifndef NEURON_HPP
#define NEURON_HPP

class Neuron{

	public:
	 ///constructor & destructor
		Neuron(double,bool,double,double,double ,double ,double,double);
		~Neuron();
		
		std::vector<Neuron> targets_;			///Neurons connected to object 

	///methodes
		bool update(int,double);  ///updates neuron state from t to t+(n*h)
		int getnbSpikes();					
		double getv_m();
		bool getrefractory();
		void receive(int,double);			///receives postsynaptic current (time t+d, weight J)					
		double geth();
		
	private: 
		int nb_spikes_;
		double v_m_; 				     		///Membrane potential (in mV)
		std::vector<double> spikes_time; 		///Times when the spikes occured
		bool refractory_;
		double v_th_;							///Threshold potential 
		double tau_;							///membrane time constant
		double mem_res_;						///membrane resistance
		double R_;								///refractory time
		double h_;								/// time interval
		int clock_;
		double delay_;
		double c1;								///constants solution differential equation
		double c2;				
		std::array<int,16> spike_buff_;		///cases represent time steps containing weight J
		
};


#endif
