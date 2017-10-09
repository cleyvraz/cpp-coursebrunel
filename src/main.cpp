#include <iostream>
#include "Neuron.cpp"
#include <fstream>

using namespace std;

int main () {
	
		Neuron neuron1;
		
	//arbitrary values 
		int tStart=0;
		int tStop=500;
		
		ofstream membrPot("membranePotentiel.txt");
		
		cout<< "Enter a current I " << endl;
		double I;
		cin>> I;
	//interval of time [a,b)
		cout << "Enter a time interval (2 numbers) between 2 and 500"<< endl;
		double a;
		double b;
		cin>>a;
		cin>>b;
	//cerr<< "a= " << a << endl;
	//cerr<< "b= " << b << endl;
		double h=10;						// time interval
		int n=tStart;						// integers: currentTime= h*n	
		
		double R=20;						//refractory time
					
		double current_I;
	
	//loop which updates neuron until tstop
		
		do{
			
		//cerr <<"n= " <<  n << endl;
			
			membrPot << neuron1.getv_m()<< "\n" ;
		//cerr << "n*h= " << n*h << endl;

			if(((n*h)>=a)&&((n*h)<=b)){
		
				current_I=I;
			}else{
			
				current_I=0;
			}
			
			neuron1.update(n,h,current_I,R);
			
			n++;
			
		}while(n*h <= tStop);
		
		membrPot.close();

}
            
