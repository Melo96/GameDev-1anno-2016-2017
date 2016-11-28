//
//  main.cpp
//  Tris
//
//  Carmelo Mammmana
//

#include <iostream>
#include <string>
#include <time.h>

using namespace std;


const int ROWS = 3;
const int COLUMNS = 3;
char grid [ROWS][COLUMNS] = { {' ', ' ', ' '},
                              {' ', ' ', ' '},
                              {' ', ' ', ' '} };

int com_row = 0;
int com_col = 0;
int turn = 1;


//FUNZIONI
int win(int turn , char p, char c);
int mossa(char c, char p);
void board(int i , int j);
void iniz_grid();

int main()
{
     srand((unsigned)time(NULL));
    
    //Indici ciclo
    int i = 0;
    int j = 0;
    
    //giocatori
    char player = 'X';
    char com = '0';
    
    
    int POS_ROW = 0;
    int POS_COL = 0;
    string difficulty = "easy";
    char choice = ' ';
    
    int r = 0;
    int risultato;
    int cont;
 
    
do
 {
     iniz_grid();
    cout << "                   TIC - TAC - TOE\n" << endl;
    
    
    cout << "\n" << endl;
    cout << "Cpu: " << com << endl;
    cout << "Player: " << player << endl;
    cout << "Difficolta':" << difficulty <<endl;
    
    cout << "\n" << endl;
    //Stampa griglia con coordinate
    for(i=0; i<ROWS; i++)
    {
        cout << "  " << endl;
        
        for(j=0; j<COLUMNS; j++)
        {
            cout << " "<< i <<   flush;
            cout << j << " |"<< flush;
        }
        
    }
    
  
        do
        {
            
            r = turn % (2);
            
            //Turno utente
            if( r != 0 )
            {
                do
                {
                    cout << "\n" << endl;
                    cout << "Scegli riga e colonna dove segnare" << endl;
                    
                    cout << "Riga:" << flush;
                    cin >> POS_ROW;
                    
                    cout << "Colonna:" << flush;
                    cin >> POS_COL;
                    
                    if((grid[POS_ROW][POS_COL] == player) || (grid[POS_ROW][POS_COL] == com))
                    {
                        cout << "\nCella occupata.Reinserire." << endl;
                    }
                    
                }
                while((grid[POS_ROW][POS_COL] == player) || (grid[POS_ROW][POS_COL]== com));
                
                grid[POS_ROW][POS_COL] = player;
                turn ++;
            }
            
            //Turno computer
            else
            {
                
                if( difficulty == "easy")
                {
                    do
                    {
                        com_row = rand() % (3);
                        com_col = rand() % (3);
                    }
                    while((grid[com_row][com_col] == player) || (grid[com_row][com_col] == com));
                    grid[com_row][com_col]= com;
                    turn++;

                }
                
                else if( difficulty == "hard")
                {
                    cont = mossa(com, player);
                    if(cont == -1)
                    {
                    
                        do
                        {
                            com_row = rand() % (3);
                            com_col = rand() % (3);
                        }
                        while((grid[com_row][com_col] == player) || (grid[com_row][com_col] == com));
                        grid[com_row][com_col]= com;
                        turn++;
                    }
                    
                    else
                    {
                        turn++;
                    }
                }
                
                
            }
        
            
            cout << "\n" << flush;
            
            risultato = win(turn, player , com);
           
            //Visualizza griglia tris
            board(i,j);

            
        }//chiusura do
        while ((risultato != 1) && (risultato != 0) && (risultato !=-1));
     
     cout << "\n" << endl;
     if((difficulty == "easy") && (risultato != -1))
     {
         cout << "\nVuoi giocare a difficolta' difficile?\nY o N" << endl;
         cin >>choice;
         
         if((choice == 'Y') || (choice == 'y'))
         {
             difficulty = "hard";
             turn = 1;
         }
     }
     
     else if((difficulty == "easy") && (risultato == -1))
     {
         cout << "\nVuoi rigiocare a difficolta' facile?\nY o N" << endl;
         cin >> choice;
         turn = 1;
     }
     
     
     else if(difficulty == "hard")
     {
         cout << "Vuoi rigiocare a difficolta' difficile?\nY o N" << endl;
         cin >> choice;
         turn = 1;
     }
     
 }
    while((choice == 'Y') || (choice == 'y'));
    
    
    
}




//Se la funzione restituisce 1 ha vinto X, se restituisce -1 ha vinto O. Se restituisce 0 è pareggio
int win(int turn, char p , char c)
{
    //Vittoria righe
    for(int i=0; i<ROWS; i++)
    {
        if((grid[i][0] == p) && (grid[i][1] == p) && (grid[i][2] == p))
        {
            cout << "Vittoria X" << endl;
            return 1;
        }
        
        else if((grid[i][0] == c) && (grid[i][1] == c) && (grid[i][2] == c))
        {
            cout << "Vittoria O" << endl;
            return -1;
        }
    }
    
    //Vittoria colonne
    
    for(int i=0; i<COLUMNS; i++)
    {
        if((grid[0][i] == p) && (grid[1][i] == p) && (grid[2][i] == p))
        {
            cout << "Vittoria X" << endl;
            return 1;
        }
        
        else if((grid[0][i] == c) && (grid[1][i] == c) && (grid[2][i] == c))
        {
            cout << "Vittoria O" << endl;
            return -1;
        }
        
    }
    
    if((grid[0][0] == p) && (grid[1][1] == p) && (grid[2][2] == p))
    {
        cout << "Vittoria X" << endl;
        return 1;
    }
    
    else if((grid[0][0] == c) && (grid[1][1] == c) && (grid[2][2] == c))
    {
        cout << "Vittoria O" << endl;
        return -1;
    }
    
    else if((grid[0][2] == p) && (grid[1][1] == p) && (grid[2][0] == p))
    {
        cout << "Vittoria X" << endl;
        return 1;
    }
    
    else if((grid[0][2] == c) && (grid[1][1] == c) && (grid[2][0] == c))
    {
        cout << "Vittoria O" << endl;
        return -1;
    }
    
    else if(turn ==10)
    {
        cout << "Pareggio" << endl;
        return 0;
    }
    
    
    return -2;
    
    
}


int mossa(char c , char p)
{
    
    
    //Controllo righe
    for(int i=0; i<ROWS; i++)
    {
        if((grid[i][0] == p) && (grid[i][1] == p) && (grid[i][2] == ' '))
        {
            grid[i][2] = c;
            return 1;
        }
        
        else if((grid[i][1] == p) && (grid[i][2] == p) && (grid[i][0] == ' '))
        {
            grid[i][0] = c;
            return 1;
        }
        
        else if((grid[i][0] == p) && (grid[i][2] == p) && (grid[i][1] == ' '))
        {
            grid[i][1] = c;
            return 1;
        }
    }
    
    for(int i=0; i<COLUMNS; i++)
    {
        if((grid[0][i] == p) && (grid[1][i] == p) && (grid[2][i] == ' '))
        {
            grid[2][i] = c;
            return 1;
        }
        
        else if((grid[1][i] == p) && (grid[2][i] == p) && (grid[0][i] == ' '))
        {
            grid[0][i] = c;
            return 1;
        }
        
        else if((grid[0][i] == p) && (grid[2][i] == p) && (grid[1][i] == ' '))
        {
            grid[1][i] = c;
            return 1;
        }
        
    }
    
    if((grid[0][0] == p) && (grid[1][1] == p) && (grid[2][2] == ' '))
    {
        grid[2][2] = c;
        return 1;
    }
    
    else if((grid[0][2] == p) && (grid[1][1] == p) && (grid[2][0] == ' '))
    {
        grid[2][0] = c;
        return 1;
    }
    
    else if((grid[0][0] == p) && (grid[2][2] == p) && (grid[1][1] == ' '))
    {
        grid[1][1] = c;
        return 1;
    }
    
    else if((grid[0][2] == p) && (grid[2][0] == p) && (grid[1][1] == ' '))
    {
        grid[1][1] = c;
        return 1;
    }
    
    else if((grid[2][0] == p) && (grid[1][1] == p) && (grid[0][2] == ' '))
    {
        grid[0][2] = c;
        return 1;
    }
    
    else if((grid[2][2] == p) && (grid[1][1] == p) && (grid[0][0] == ' '))
    {
        grid[0][0] = c;
        return 1;
    }
    
    
    return -1;
    
    
}


void board(int i,int j)
{
    for(i=0; i<ROWS; i++)
    {
        cout << " " <<  endl;
        //cout << " |" << flush;
        
        for(j=0; j<COLUMNS; j++)
        {
            cout << " " << grid[i][j] << flush;
            cout << " |"<< flush;
        }
    }
    cout << "\n" << endl;
    
    

}

void iniz_grid()
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLUMNS; j++)
        {
            grid[i][j] = ' ';
        }
    }
}



