//
//  main.cpp
//  Es2_12012016
//
//  Created by Carmelo Mammana on 01/12/16.
//  Copyright © 2016 Carmelo Mammana. All rights reserved.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

vector < vector <int> > grid(5);
vector < vector <int> > :: iterator it;
int trap_r;
int trap_c;
int treasure_r;
int treasure_c;
int hero_r;
int hero_c;
char check = ' ';




void ViewGrid( vector <vector <int> >& grid);
void NewGrid( vector <vector <int> >& grid);
void TrapGenerator( vector <vector <int> >& grid);
void TreasureGenerator( vector <vector <int> >& grid);
void HeroSpawn( vector <vector <int> >& grid);
void HeroMove( vector <vector <int> >& grid);
void Check(vector < vector <int> >& grid, int r, int c);




int main()
{
    srand(time(NULL));
    
   do
   {
       //Inizializzo griglia di gioco
       for(int i=0; i<5; i++)
       {
           grid[i].resize(5);
        
       }
    
    
       cout << "\nBenvenuto nella stanza del Dungeon.Il tuo obbiettivo e' quello di raggiungere il tesoro cercando di non attivare le trappole.Puoi muovere l'eroe a destra, sinistra, su e giu'.\n" << endl;
       cout << "\nComandi:\nw -> movimento di una cella verso l'alto\ns -> movimento di una cella verso il basso\na -> movimento di una cella verso sinistra\nd -> movimento di una cella verso destra\n" << endl;
    
       cout << "\nLegenda di gioco:\nEroe -> 7\nTrappole -> 5\nTesoro -> 1\nSpazio vuoto -> 0\n" << endl;
       NewGrid(grid);
       TrapGenerator(grid);
       TreasureGenerator(grid);
       HeroSpawn(grid);
    
    
       do
       {
           ViewGrid(grid);
           HeroMove(grid);
       }
       while((check != 'y') && (check != 'n'));
       
       if(check == 'y')
       {
           check = ' ';
       }

   }
    while(check == ' ');
    
}

//Visualizza griglia per gioco
void ViewGrid(vector <vector <int> >& grid)
{
    for(int i=0; i<5; i++)
    {
        cout << " " << endl;
        for(int j=0; j<5; j++)
        {
            if(grid[i][j] == 5)
            {
                cout << " 0" << flush;
            }
            
            
            else
            {
                cout << " " << grid[i][j] << flush;
            }
        }
    }
    cout << "\n" << endl;
    return;
}

void NewGrid(vector <vector <int> >& grid)
{
    for(int i=0; i<5; i++)
    {
        cout << " " << endl;
        for(int j=0; j<5; j++)
        {
            grid[i][j] = 0;
        }
    }
}


//Genera trappole sulla griglia
void TrapGenerator(vector <vector <int> >& grid)
{
    for(int i=0; i<3; i++)
    {
        trap_r = rand() % (4);
        trap_c = rand() % (4);

        if(grid[trap_r][trap_c] == 5)
        {
            do
            {
                trap_r = rand() % (4);
                trap_c = rand() % (4);
            }
            while(grid[trap_r][trap_c] != 0);
        }
        grid[trap_r][trap_c] = 5;
        
    }
    return;
}



//Genera tesoro sulla griglia
void TreasureGenerator( vector < vector <int> >& grid)
{
    do
    {
        treasure_r = rand() % (4);
        treasure_c = rand() % (4);
    }
    while((treasure_r == 5) && (treasure_c == 5));
    
    grid[treasure_r][treasure_c] = 1;
}




//Spawna l'eroe sulla griglia
void HeroSpawn( vector <vector <int> >& grid)
{
    do
    {
        hero_r = rand() % (4);
        hero_c = rand() % (4);
    }
    while((hero_r == 5) && (hero_c == 5) && (hero_r == 1) && (hero_c == 1));
    
    grid[hero_r][hero_c] = 7;
}




//Muove l'erore e controlla vittoria o sconfitta
void HeroMove( vector <vector <int> >& grid)
{
    char move;
    
    cout <<"\nMuovi il giocatore" << endl;
    
    cin >> move;
    if((move == 'w') && (hero_r >= 0))
    {
        
        if(hero_r == 0)
        {
            cout << "Non puoi uscire dai bordi. Prova un' altra mossa." << endl;
        }
        else
        {
           
            grid[hero_r][hero_c] = 0;
            hero_r = hero_r - 1;
            Check(grid, hero_r, hero_c);
  
        }
    
    }
    
    
    else if(move == 's')
    {
        if(hero_r == 4)
        {
            cout << "Non puoi uscire dai bordi. Prova un' altra mossa." << endl;
        }
        
        else
        {
            grid[hero_r][hero_c] = 0;
            hero_r = hero_r + 1;
            
            Check(grid, hero_r, hero_c);
        }
        
    }
    
    else if(move == 'a')
    {
        if(hero_c == 0)
        {
            cout << "Non puoi uscire dai bordi. Prova un' altra mossa." << endl;
        }
        else
        {
            grid[hero_r][hero_c] = 0;
            hero_c = hero_c - 1;
        
            Check(grid, hero_r, hero_c);
        }
    }
    
    else if(move == 'd')
    {
        if(hero_c == 4)
        {
            cout << "Non puoi uscire dai bordi. Prova un' altra mossa." << endl;
        }
        else
        {
            grid[hero_r][hero_c] = 0;
            hero_c = hero_c + 1;
        
            Check(grid, hero_r, hero_c);
        }
    }
}


//Controlla vittoria o sconfitta
void Check(vector < vector <int> >& grid, int r, int c)
{
    if(grid[r][c] == 5)
    {
        cout << "\nHai perso!Sei finito su una trappola" << endl;
        
        cout << "\nVuoi rigiocare? Y o N" << endl;
        cin >> check;
        
        return;
    }
    
    else if(grid[r][c] == 1)
    {
        cout << "\nHai vinto!Hai trovato il tesoro" << endl;
        
        cout << "\nVuoi rigiocare? Y o N" << endl;
        cin >> check;
        
        return ;
    }
    
    else
    {
        grid[r][c] = 7;
        
    }

    
    
    
    
    
}










