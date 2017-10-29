#include <iostream>
#include "Network.hpp"
#include <fstream>

using namespace std;

int main (){
	
		Network network;
		int tStart=0;
		int tStop=500;
		
		ofstream membrPot("membranePotentiel.txt");
		
/*
		
		do
		{
			
			cout<< "Enter a current I between 0 and 10" << endl;
			cin>> I;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				I=11; // /!\ à changer /!\ si cin.fail() boucle continue
			}
		}while((I<0)||(I>10));
		*/
		double a;
		double b;

		do
		{
			cout << "Enter a time interval (2 numbers) between 2 and 500"<< endl;
			cin>>a;
			cin>>b;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				 // /!\ à changer /!\ si cin.fail() boucle continue
			}
		}while(((a<2)||(a>tStop)) || ((b<2)||(b>tStop)) || (b<a));

		
		int n=tStart;						/// clock in step currentTime= h*n
					
		do
		{			
			/*cout<<"boucle n°: "<< n<< endl;

			if((n>=a)&&(n<=b)){
				current_I=I; 
			}else{

				current_I=0;
			}*/			
			membrPot << network.getneuron(1).getv_m()<< "\n" ;

			network.update(n); 			///scans each neurons, calls update and receive
			n++;
		}while(n <= tStop);
		
		membrPot.close();
}
            
