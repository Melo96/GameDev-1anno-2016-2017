//
//  main.cpp
//  Es3_12012016
//
//  Created by Carmelo Mammana on 01/12/16.
//  Copyright © 2016 Carmelo Mammana. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

vector < vector <int> > grid(5);
vector < vector <int> > :: iterator it;
int enemy_r1=0;
int enemy_c1=0;


int enemy_r2=0;
int enemy_c2=0;


int enemy_r3=0;
int enemy_c3=0;


int treasure_r=0;
int treasure_c=0;
int hero_r=0;
int hero_c=0;
int block_r=0;
int block_c=0;
char check = ' ';





void ViewGrid( vector <vector <int> >& grid);
void NewGrid( vector <vector <int> >& grid);
int EnemyGeneratorRows( vector <vector <int> >& grid);
int EnemyGeneratorColumns( vector <vector <int> >& grid);
void TreasureGenerator( vector <vector <int> >& grid);
void BlockGenerator( vector <vector <int> >& grid);
void HeroSpawn( vector <vector <int> >& grid);
void HeroMove( vector <vector <int> >& grid);
void Check_Hero_Move(vector < vector <int> >& grid, int r, int c);
void Check_Enemy_Move(vector < vector <int> >& grid, int r, int c);
void EnemyMove( vector <vector <int> >& grid);




int main()
{
    srand((unsigned)time(NULL));
    
    do
    {
        //Inizializzo griglia di gioco
        for(int i=0; i<5; i++)
        {
            grid[i].resize(5);
            
        }
        
        
        cout << "\nBenvenuto nella stanza del Dungeon.Il tuo obbiettivo e' quello di raggiungere il tesoro cercando di non incrociare i nemici.Puoi muovere l'eroe a destra, sinistra, su e giu'.\n" << endl;
        cout << "\nComandi:\nw -> movimento di una cella verso l'alto\ns -> movimento di una cella verso il basso\na -> movimento di una cella verso sinistra\nd -> movimento di una cella verso destra\n" << endl;
        
        cout << "\nLegenda di gioco:\nEroe -> 7\nNemico -> 5\nTesoro -> 1\nSpazio vuoto -> 0\nBlocco -> 6\n" << endl;
        NewGrid(grid);
       
        do
        {
            enemy_r1 = EnemyGeneratorRows(grid);
            enemy_c1 = EnemyGeneratorRows(grid);
        }
        while(grid[enemy_r1][enemy_c1] != 0);
        
        do
        {
            enemy_r2 = EnemyGeneratorRows(grid);
            enemy_c2 = EnemyGeneratorRows(grid);
        }
        while(grid[enemy_r2][enemy_c2] != 0);
        
        do
        {
            enemy_r3 = EnemyGeneratorRows(grid);
            enemy_c3 = EnemyGeneratorRows(grid);
        }
        while(grid[enemy_r3][enemy_c3] != 0);
        
        
        
        
        TreasureGenerator(grid);
        BlockGenerator(grid);
        HeroSpawn(grid);
        
        
        do
        {
            ViewGrid(grid);
            HeroMove(grid);
            EnemyMove(grid);
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
           /* if(grid[i][j] == 5)
            {
                cout << " 0" << flush;
            }
            
            
            else if(grid[i][j] != 5)
            {*/
                cout << " " << grid[i][j] << flush;
           // }
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
    
    return;
}


//Genera nemici sulla griglia
int EnemyGeneratorRows(vector <vector <int> >& grid )
{
    int r;
    r = rand() % (4);
    
    return r;
}

int EnemyGeneratorColumns(vector <vector <int> >& grid )
{
    int c;
    c = rand() % (4);
    
    return c;
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
    
    return;
}





//Genera tre blocchi sulla griglia
void BlockGenerator(vector <vector <int> >& grid)
{
    for(int i=0; i<3; i++)
    {
        block_r = rand() % (4);
        block_c = rand() % (4);
        
        
            do
            {
                block_r = rand() % (4);
                block_c = rand() % (4);
            }
            while(grid[block_r][block_c] != 0);
        
        grid[block_r][block_c] = 6;
        
    }
    return;

}



//Spawna l'eroe sulla griglia
void HeroSpawn( vector <vector <int> >& grid)
{
    srand((unsigned)time(NULL));
    do
    {
        hero_r = rand() % (4);
        hero_c = rand() % (4);
    }
    while((hero_r == 5) && (hero_c == 5) && (hero_r == 1) && (hero_c == 1));
    
    grid[hero_r][hero_c] = 7;
}




//Muove l'eroe e controlla vittoria o sconfitta
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
            
            Check_Hero_Move(grid, hero_r, hero_c);
            
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
            
            Check_Hero_Move(grid, hero_r, hero_c);
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
            
            Check_Hero_Move(grid, hero_r, hero_c);
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
            
            Check_Hero_Move(grid, hero_r, hero_c);
        }
    }
}


//Controlla vittoria o sconfitta
void Check_Hero_Move(vector < vector <int> >& grid, int r, int c)
{
    if(grid[r][c] == 5)
    {
        cout << "\nHai perso!Il nemico ti ha ucciso" << endl;
        
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
    
    else if(grid[r][c] == 6)
    {
        cout << "\nNon puoi scavalcare questi blocchi. Prova con un'altra mossa" << endl;
        HeroMove(grid);
        
    }
    
    else
    {
        grid[r][c] = 7;
        
    }

}

void Check_Enemy_Move(vector < vector <int> >& grid, int r, int c)
{
    if(grid[r][c] == 6)
    {
        EnemyMove(grid);
    }
    
    else if(grid[r][c] == 1)
    {
        EnemyMove(grid);
    }
    
    else if(grid[r][c] == 7)
    {
        cout << "\nHai perso!Il nemico ti ha ucciso" << endl;
        
        cout << "\nVuoi rigiocare? Y o N" << endl;
        cin >> check;
        
        return;
    }
    
    else
    {
        grid[r][c] = 5;
    }
    
    
    
}

void EnemyMove( vector <vector <int> >& grid, int r,int c)
{
    
    srand((unsigned)time(NULL));
    int n;
    
    n = rand() % (4 + 1);
    
    if(n == 1)
    {
            if(r == 0)
            {
                EnemyMove(grid);
                
            }
            else
            {
                grid[r][c] = 0;
                r = r - 1;
                
                Check_Enemy_Move(grid, r, c);
                
            }
    }
    
            
    else if(n == 2)
    {
            if(r == 4)
            {
                EnemyMove(grid);
                
            }
            else
            {
                grid[r][c] = 0;
                r = r + 1;
                
                Check_Enemy_Move(grid, r, c);
                
            }
    }
    
    
      else if(n == 3)
      {
    
            if(r == 0)
            {
                EnemyMove(grid);
                
            }
            else
            {
                grid[r][c] = 0;
                c = c - 1;
                
                Check_Enemy_Move(grid, r, c);
                
            }
      }
    
            
    else if(n == 4)
    {
            if(c == 4)
            {
                EnemyMove(grid);
                
            }
            else
            {
                grid[r][c] = 0;
                c = c + 1;
                
                Check_Enemy_Move(grid, r, c);
                
            }
    }
    
            
    
    
}












