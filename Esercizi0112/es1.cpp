//
//  main.cpp
//  Es1_12012016
//
//  Created by Carmelo Mammana on 01/12/16.
//  Copyright © 2016 Carmelo Mammana. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;


vector <string> Mercantile;
vector <string> :: iterator it;


//Funzioni
void View_Hold(vector <string>& Mercantile);
void Add_Merchandise(string s , vector <string>& Mercantile);
void Lost_LastMerchandise(vector <string>& Mercantile);
void Add_FriendsMerchandise(vector <string>& Mercantile);
void Change_Merchandise(vector <string>& Mercantile);
void Pirates_Attack(vector <string>& Mercantile);
void Sort_Alphabetical(vector <string>& Mercantile);
void Tempest_Sort(vector <string>& Mercantile);
void Sell_Merchandise(vector <string>& Mercantile);




int main()
{
    
    string merchandise;
    int i = 0;
    
    cout << "Al mercantile verranno aggiunte le seguenti merci:\nvino\nlana\navorio\nlegno.\nDigitare uno ad uno il nome della merce per aggiungerla." << endl;
    while(i!=4)
    {
        cout << "\n" ;
        cin >> merchandise;
        
        Add_Merchandise(merchandise, Mercantile);
        i++;
    }
    View_Hold(Mercantile);
    cout << "\n";
    
    Lost_LastMerchandise(Mercantile);
    cout << "\n";
    
    View_Hold(Mercantile);
    cout << "\n";
    
    Add_FriendsMerchandise(Mercantile);
    cout << "\n";
    
    View_Hold(Mercantile);
    cout << "\n";
    
    Change_Merchandise(Mercantile);
    cout << "\n";
    
    View_Hold(Mercantile);
    cout << "\n";
    
    Pirates_Attack(Mercantile);
    cout << "\n";
    
    View_Hold(Mercantile);
    cout << "\n";
    
    Sort_Alphabetical(Mercantile);
    cout << "\n";
    
    View_Hold(Mercantile);
    cout << "\n";
    
    Tempest_Sort(Mercantile);
    cout << "\n";
    
    View_Hold(Mercantile);
    cout << "\n";
    
    Sell_Merchandise(Mercantile);
    cout << "\n";
    
    View_Hold(Mercantile);
    cout << "\n";
   
    
    
    
    
    
    
    
    
}

void View_Hold(vector <string>& Mercantile)
{
    cout << "La tua stiva è composta da:\n" ;
    for(it = Mercantile.begin(); it != Mercantile.end(); it++)
    {
        cout << *it;
        cout << "\n";
    }
    
    return;
}




void Add_Merchandise(string s , vector <string>& Mercantile)
{
    
        Mercantile.push_back(s);
        cout << s << " e' stato aggiunto al mercantile" << endl;
    
    return;

}

void Lost_LastMerchandise(vector <string>& Mercantile)
{
    cout << "\n" ;
    cout << "L'ultimo carico di merci non e' stato adeguatamente legato. Il carico di " << Mercantile.back() << " e' caduto in mare\n" << endl;
    
    it = find(Mercantile.begin(), Mercantile.end(), "legno");
    
    Mercantile.erase(it);
    
    
    return;

    
}

void Add_FriendsMerchandise(vector <string>& Mercantile)
{
    cout <<"Lungo il viaggio un mercante amico ti dona un carico di te'" << endl;
    it = Mercantile.begin();
    Mercantile.insert(it, "te'");
    
    return;

    
}


void Change_Merchandise(vector <string>& Mercantile)
{
    cout << "Arrivato ad un mercato decidi di scambiare della lana con del frumento" << endl;
    
    it = find(Mercantile.begin(), Mercantile.end(), "lana");
    if( it != Mercantile.end())
    {
        Mercantile.erase(it);
        Mercantile.insert(it, "frumento");
    }
    
    else
    {
        cout << "La lana non è presente nella stiva, non è stato possibile effettuare lo scambio\n" << endl;
    }
    
    return;


}



void Pirates_Attack(vector <string>& Mercantile)
{
    cout << "Durante il viaggio dei pirati golosi di vino ti attaccano rubandoti tutto il vino\n" << endl;
    
    it = find(Mercantile.begin(), Mercantile.end(), "vino");
    Mercantile.erase(it);
    
    return;

}



void Sort_Alphabetical(vector <string>& Mercantile)
{
    sort(Mercantile.begin(), Mercantile.end());
    
    return;

}


void Tempest_Sort(vector <string>& Mercantile)
{
    srand(time(NULL));
    cout <<"\nArriva una tempesta. La tua stiva viene messa in disordine" << endl;
    random_shuffle(Mercantile.begin(), Mercantile.end());
    
    return;

}


void Sell_Merchandise(vector <string>& Mercantile)
{
    cout << "\nSei arrivato al mercato di Tiro. Vendi tutta la tua merce per dell'oro" << endl;
    
    Mercantile.clear();
    Mercantile.push_back("oro");
    
    return;

}















