#include <iostream>
#include <string>
using namespace std;

int main()
{
    
  	int leaderboard[10];
  	int media = 0;
  
  	for(int i=0; i<10; i++)
 	 {
   	   	cout << "Inserire punteggio giocatore" << i << ": " << endl;
    	cin >> leaderboard[i];
      
  	}
  
  	for(int i=9; i>=0; i--)
  	{
  	  cout << "Punteggio giocatore" << i << ": " << leaderboard[i] << endl;
      media = media + leaderboard[i];
  	}
  	
  	media = (media / 10);
  	
  	cout << "La media dei punteggi è: " << media << endl;
  	
  }
