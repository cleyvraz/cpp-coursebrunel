#include <iostream>
#include "Neuron.cpp"
#include "Network.cpp"
#include <fstream>

using namespace std;

int main () {
	
		Network network;
		//Neuron neuron1;
		//Neuron neuron2;
		//network.addneuron(neuron1);
		//network.addneuron(neuron2);
	///arbitrary values 
		int tStart=0;
		int tStop=500;
		
		ofstream membrPot("membranePotentiel.txt");
		
		double I;
		
		do{
			
			cout<< "Enter a current I between 0 and 10" << endl;
			cin>> I;
			if(cin.fail()){
				cin.clear();
				cin.ignore(10000, '\n');
				I=11; // /!\ à changer /!\ si cin.fail() boucle continue
			}
		}while((I<0)||(I>10));
		
	///interval of time [a,b)
		double a;
		double b;
		
		do{
			cout << "Enter a time interval (2 numbers) between 2 and 500"<< endl;
			
			cin>>a;
			cin>>b;
			if(cin.fail()){
				cin.clear();
				cin.ignore(10000, '\n');
				I=1; // /!\ à changer /!\ si cin.fail() boucle continue
			}
		}while(((a<2)||(a>500)) || ((b<2)||(b>500)) || (b<a));
		
		int n=tStart;						/// clock in step currentTime= h*n			
		double current_I;
		do{
			//membrPot << neuron1.getv_m()<< "\n" 
			if((n>=a)&&(n<=b)){
				current_I=I;
			}else{
				current_I=0;
			}
			network.connect(n,current_I); 			///scans each neurons, calls update and receive
			//neuron1.update(n,h,current_I,R);
			n++;
			
		}while(n <= tStop);
		
		membrPot.close();
}
            
