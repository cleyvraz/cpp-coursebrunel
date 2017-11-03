#include "Network.hpp"

using namespace std;

int main (){
	
		Network network;
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
			if(tStop>500)
			{
				cerr<< "The simulation should last 500ms or less !" << endl;
			}
		}while(tStop>500);

		unsigned int n=tStop/0.1;			///clock in step currentTime= h*n
		network.runsimulation(n); 			///scans each neurons, calls update and receive
}
            
