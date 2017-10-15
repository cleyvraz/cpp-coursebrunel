#include <iostream>
#include "Neuron.hpp"
#include "Network.cpp"
#include <fstream>

using namespace std;

int main () {
	
		Network network;
		
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
		
		double h=0.1;						/// time interval
		int n=tStart;						/// integers: currentTime= h*n	
		
		double R=20;						///refractory time
					
		double current_I;
	
		
		do{
		
			//membrPot << neuron1.getv_m()<< "\n" ;

			if(((n*h)>=a)&&((n*h)<=b)){
		
				current_I=I;
			}else{
			
				current_I=0;
			}
			network.connect(n,h,current_I,R);

			//neuron1.update(n,h,current_I,R);
			
			n++;
			
		}while(n*h <= tStop);
		
		membrPot.close();

}
            
