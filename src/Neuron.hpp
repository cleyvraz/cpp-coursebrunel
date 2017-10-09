#include <vector>


class Neuron{

	public:
	 //constructor & destructor
		Neuron(double,bool,double,double,double);
		~Neuron();
	//methodes
		void update(int,double,double,double);       //updates neuron state from t to t+(n*h)
		int getnbSpikes();
		double getv_m();
		bool getrefractory();
		
	private: 
		int nb_spikes_;
		double v_m_; 				     		//Membrane potential (in mV)
		std::vector<double> spikes_time; 		//Times when the spikes occured
		bool refractory_;
		double v_th_;							//Threshold potential 
		double tau_;							//membrane time constant
		double mem_res_;						//membrane resistance
		double clock_;
							
		
};
