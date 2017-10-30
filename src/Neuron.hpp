#include <vector>

#ifndef NEURON_HPP
#define NEURON_HPP

class Neuron
{

	public:
	 //!constructor & destructor
		Neuron(double m=0,bool r=false,double sth=20 ,double t=20 ,double c=0,double d=15,double rcst=20,double h=0.1,double i=0.0, double j=0.1);
		~Neuron();
	
	//!methodes
		bool update(int);  					/*!updates neuron state from t to t+(n*h)*/
		int getnbSpikes();					
		double getv_m();
		bool getrefractory();
		void receive(int,double);			/*!receives postsynaptic current (time t+d, weight J)*/					
		double geth();
		//std::vector<Neuron*> gettargets();
		void setI(double);
		unsigned int gettargetsize();
		unsigned int gettargets(unsigned int);
		void addtarget(unsigned int i);
		

	private: 
		int nb_spikes_;
		double v_m_; 				     		/*!Membrane potential (in mV)*/
		std::vector<double> spikes_time; 		/*!Times when the spikes occured*/
		bool refractory_;
		double v_th_;							/*!Threshold potential*/ 
		double tau_;							/*!membrane time constant*/
		double mem_res_;						/*!membrane resistance*/
		double R_;								/*!refractory time*/
		double h_;								/*! time interval*/
		int clock_;
		double delay_;
		double c1;								/*!constants for the solution differential equation*/
		double c2;	
		double i_ext_;		
		double j_ext;	
		std::vector<double> spike_buff_;			// à changer ///cases represent time steps containing weight J
		std::vector<unsigned int> targets_;			/*!Neurons connected to object */

};

#endif
