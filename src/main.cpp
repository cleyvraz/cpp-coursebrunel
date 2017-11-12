#include "Network.hpp"
#include <iostream>

using namespace std;

void experiment(); 


int main ()
{
	experiment();
}
 

 
 /******************************EXPERIMENT*************************
  * Experiment asks the user how long the simlutation should last,
  * and which case (different graphs) it should produce.
  * I chose not to do a class experiment as it wouldn't really add
  * anything more than this function 
	***************************************************************/
 void experiment()
{
	unsigned int tStop;
	do
	{
		cout << "How long would you like the simulation to run? (in ms)"<< endl;
		cin>>tStop;
		while(cin.fail())
		{	
		cerr<< "Not a number! " << endl;			
		cin.clear();
		cin.ignore(10000, '\n');
		cin >>tStop;
		}
		if((tStop>1500) or (tStop<300))
		{
			cerr<< "The simulation should last between 300ms and 1500ms !" << endl; //conditions can be changed but the graph will show the intervall 100ms-300ms (can be changed too)
		}
		}while((tStop>1500) or (tStop<300));
		char j;
		do
		{
			cout<< "What graph do you want to have? (a,b,c,d)" << endl;
			cin>>j;
		}while((j!='a')&&(j!='b')&&(j!='c')&&(j!='d'));
			
		double g;
		double e;
			
		if(j=='a')
		{ cout<<"g=3, eta=2"<< endl;
			g=3.0;
			e=2.0;
		}
		if(j=='b')
		{ cout<<"g=6, eta=4"<< endl;
			g=6.0;
			e=4.0;
		}
		if(j=='c')
		{ cout<<"g=5, eta=2"<< endl;
			g=5.0;
			e=2.0;
		}
		if(j=='d')
		{ cout<<"g=4.5, eta=0.9"<< endl;
			g=4.5;
			e=0.9;
		}
			
		Network network(e,g);
		unsigned int n=(tStop/0.1);			///clock in steps: currentTime= h*n
		network.runsimulation(n); 			///scans each neurons n times, calls update and receive
	}
