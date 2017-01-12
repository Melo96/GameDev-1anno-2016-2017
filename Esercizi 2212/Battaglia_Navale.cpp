
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

//Dichiarazione funzioni
void StartGame();
int  CheckPlace(int num, int x, int y, int Board[10][10]);
void Placement(int num, int x, int y, int err, int Board[10][10]);
void StartBoard(int Board[10][10]);
void PrintBoard(int Board[10][10], bool b);
void PrintBoard(int Board[10][10], int Board1[10][10]);
void PrintInstruction();
void PlacePlayer(int Board[10][10]);
int ReturnNumb(char ch);
void Fire();
void CheckFire(int x, int y, int Board[10][10]);





bool horizontal;  //Flag che mi servono per capire la direzione in cui posizionare la barca
bool vertical;



int BoardCom[10][10];
int BoardPlr[10][10];
char Alphabet [10] = {'A','B','C','D','E','F','G','H','I','L'};
bool turn = true;
int HitCom = 0;
int HitPlr = 0;


/*void StartGame()
{
    int x,y;
    int num=5;
    int err;
 
 
    StartBoard();
    PrintBoard();
 
 
    for(num = 5; num > 0; num--)
    {
        do
        {
            x = rand() % 10;
            y = rand() % 10;
 
            err = CheckPlace(num, x, y);
        }
        while(err == -1);
 
    Placement(num, x, y, err);
    horizontal = false;
    vertical = false;
 }
 


 
 
}
*/



int CheckPlace(int num , int x, int y, int Board[10][10])
{
 
    
    //Controllo verticale
    if(y + num < 10) //Se la barca entra nella board in verticale controllo che non ce ne siano altre
    {
        int dy;
        int dm = num + y;
        for(dy = y; dy < dm; dy++)
        {
            if(Board[x][dy] != 0)
            {
                x = rand() % 10;
                y = rand() % 10;
                CheckPlace(num, x, y, Board);
                
            }
        }
        
        //if(dy != 0)
        //{
            vertical = true;
            return 1;
        //}
        
        //else
        //{
         //   vertical = false;
            
        //}
    

    }
    
    
    
    else if(x + num < 10) //Se la barca entra nella board in orizzontale controllo che non ce ne siano altre
    {
        int dx;
        int dm = num + x;
        for(dx = x; dx < dm; dx++)
        {
            if(Board[dx][y] != 0)
            {
                x = rand() % 10;
                y = rand() % 10;
                CheckPlace(num, x, y,Board);
            }
        }
        
        //if(dx != 0)
        //{
            horizontal = true;
            return 2;
        //}
        
       // else
       // {
         //   horizontal = false;
            
        //}
        
    }
    
    else if(x + num > 10) //Se la barca non entra nella board in orizzontale controllo che non ce ne siano altre
    {
        int dx;
        int dm = x - num;
        for(dx = x; dx > dm; dx--)
        {
            if(Board[dx][y] != 0)
            {
                x = rand() % 10;
                y = rand() % 10;
                CheckPlace(num, x, y,Board);
            }
        }
        
        if(dx != 0)
        {
            horizontal = true;
            return -2;
        }
        
        else
        {
            horizontal = false;
            
        }
        
    }
    
    else if(y + num > 10) //Se la barca non entra nella board in verticale controllo che non ce ne siano altre
    {
        int dy;
        int dm = y - num;
        for(dy = dm; dy > dm; dy--)
        {
            if(Board[x][dy] != 0)
            {
                x = rand() % 10;
                y = rand() % 10;
                CheckPlace(num, x, y,Board);
            }
        }
        
        if(dy != 0)
        {
            horizontal = true;
            return -1;
        }
        
        else
        {
            horizontal = false;
            
        }
        
    }
    
    
    
    return -1;
}


void Placement(int num, int x, int y, int err, int Board[10][10])
{
    
    if(err == 1)
    {
        //Posiziono la barca in verticale
        
        int dy;
        int dm = num + y;
        for(dy = y; dy < dm; dy++)
        {
            Board[x][dy] = num;
        }
        //cout << "\nBarca posizionata" << endl;
    }
    
    else if(err == 2)
    {
        //Posiziono la barca in orizzontale
        
        int dx;
        int dm = num + x;
        for(dx = x; dx < dm; dx++)
        {
            Board[dx][y] = num;
        }
        //cout << "\nBarca posizionata" << endl;
    }
    
    else if(err == -1)
    {
        int dy;
        int dm = y - num;
        for(dy = y; dy > dm; dy--)
        {
            Board[x][dy] = num;
        }
    }
    
    else if(err == -2)
    {
        int dx;
        int dm = x - num;
        for(dx = x; dx > dm; dx--)
        {
            Board[dx][y] = num;
        }
    }
    
}

void StartBoard(int Board[10][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            Board[i][j] = 0;
    }
}

void PrintBoard(int Board[10][10], bool b)  // DA RISISTEMARE
{
    if(b)
    {
        cout << "\n\tComputer\n" << endl;
        
        
        for(int i=0; i<10; i++)
        {
            //cout << "  " << flush;
            cout << "    " << Alphabet[i] << " " << flush;
        }
        
        
        for(int i=0; i<10; i++)
        {
            cout << "\n" << i + 1 << " " <<  flush;
            for(int j=0; j<10; j++)
            {
                if((Board[i][j] == '0') || (Board[i][j] == '1') || (Board[i][j] == 8) )
                {
                    if(i == 9)
                        cout << " " << Board[i][j] << "    " << flush;
                    
                    else
                        cout << "  "<< Board[i][j] << "   " << flush;
                }
                
                else
                {
                    if(i == 9)
                        cout << " " << Board[i][j] << "    " << flush;
                    
                    else
                        cout << "  "<< "0" << "   " << flush;
                }
            }
        }
        
        cout << "\n" << endl;
        
    }
    else
    {
        cout << "\n\tPlayer\n" << endl;
    
    
        for(int i=0; i<10; i++)
        {
            //cout << "  " << flush;
            cout << "    " << Alphabet[i] << " " << flush;
        }
    
    
        for(int i=0; i<10; i++)
        {
            cout << "\n" << i + 1 << " " <<  flush;
            for(int j=0; j<10; j++)
            {
                if(i == 9)
                    cout << " " << Board[i][j] << "    " << flush;
                else
                    cout << "  "<< Board[i][j] << "   " << flush;
            }
        }
    
        cout << "\n" << endl;
        }
}



void PrintBoard(int Board[10][10], int Board1[10][10])
{
    cout << "\n\tBattleship" << endl;
    for(int i=0; i<10; i++)
    {
        cout << "\n" << flush;
        cout << "\t\t\t\t\t" << flush;
        for(int j=0; j<10; j++)
        {
            cout << " "<< Board[i][j] << " " << flush;
            cout << " "<< Board1[i][j] << " " << flush;
        
        }
        
    }
    
    /*
    for(int i=0; i<10; i++)
    {
        cout <<  "" << flush;
        for(int j=0; j<10; j++)
            cout << " "<< Board1[i][j] << " " << flush;
    }*/
    
}


void PrintInstruction()
{
    cout << "\n                                                                                                                                                                   " << endl;
    cout << "\n                                                                                                                                                                   " ;
    cout << "\n                                                                                                                                                                   " ;
    cout << "\n                                                                                                                                                                   " ;
    cout << "\n                                                                                                                                                                   " ;
    cout << "\n   ------------------------------------                                                                                                Navi colpite CPU: " << HitCom  ;
    cout << "\n                                                                                                                                       Navi Colpite Utente: " << HitPlr ;
    cout << "\n                                                                                                                                                                   " ;
    cout << "\n                                                                                                                                                                   " ;
    cout << "\n                                                                                                                                                                   " ;
    cout << "\n                                                                                                                                                                   " ;
}


void PlacePlayer(int Board[10][10])
{
    int x , y, err;
    char ch;
    
    
    for(int num=5; num > 0 ; num--)
    {
        cout << "\nScegli dove vuoi posizionare la nave da "<< num <<"\nInserisci la riga e la colonna." << endl;
        do
        {
            cout << "\nRiga: "<< flush;
            cin >> x;
    
            cout << "\nColonna: "<< flush;
            cin >> ch;
            ch = putchar(toupper(ch));
            y = ReturnNumb(ch);

            err = CheckPlace(num, x-1, y, Board);
        }
        while(Board[x][y] != 0);
        
        Placement(num, x-1, y, err, Board);
        horizontal = false;
        vertical = false;
        
    }
    
    
    
}

int ReturnNumb(char ch)
{
    int x;
    
    for(int i=0; i<10;i++)
    {
        if(ch == Alphabet[i])
        {
            x = i;
            i = 10;
        }
    }
    
    return x;
    
}



void Fire()
{
    if(turn)  //TRUE = TURNO COMPUTER
    {
        int x, y, dx, dy;
        
        
        
        do
        {
              x = rand() % 10;
              y = rand() % 10;

              dx = x;
              dy = y;
        }
        while(( x != dx ) || ( y != dy));
        
        CheckFire(x, y, BoardPlr);
        
        turn = false;
    }
    
    else
    {
        int x, y;
        char ch;
        
        
        cout << "\nE' il tuo turno, inserisci la riga dove vuoi colpire: "<< flush;
        cin >> x;
        cout << "\nColonna: " << flush;
        cin >> ch;
        ch = putchar(toupper(ch));
        y = ReturnNumb(ch);
        
        CheckFire(x-1, y, BoardCom);
        
        turn = true;
    }
}


void CheckFire(int x, int y, int Board[10][10])
{
    if(Board[x][y] != 0)
    {
        Board[x][y] = '8';
        
        cout << "\nNave Colpita" << endl;
        if(turn)
            HitCom ++;
        else
            HitPlr ++;
    }
    
    else
    {
        Board[x][y] = '1';
        cout << "\nNessuna nave colpita" << endl;
    }
}







int main()
{
    srand(time(NULL));
    
    int x;
    int y;
    
    int num=5;
    int err;
    
    
    StartBoard(BoardCom);
   
    
    
    for(num = 5; num > 0; num--)
    {
       do
        {
            x = rand() % 10;
            y = rand() % 10;
            
            err = CheckPlace(num, x, y,BoardCom);
        }
        while(err == -1);
        
        Placement(num, x, y, err,BoardCom);
        horizontal = false;
        vertical = false;
    }
   

    
    
    //PrintBoard(BoardCom,true);
    
    
    cout << "\n\t\t\tBATTLESHIP" << endl;
    cout << "Benvenuto nel gioco della battaglia navale." << endl;
    cout << "Il gioco è semplice, dovrai inserire la riga e la colonna di dove vorrai colpirecercando di affondare le navi avversarie.\nVince chi le affonda tutte per primo. " << endl;
    
    cout << "Scegli se essere primo o secondo e posiziona le tue navi. Buona fortuna!" << endl;
    
    cout << "\n1-PRIMO\n2-SECONDO" << endl;
    
    int scelta;
    
    cin >> scelta;
    
    if(scelta == 1)
        turn = false;
    
    else
        turn = true;
    
    
    cout << "\n                                                                                                                                       A B C D E F G H I L          " << endl;
    cout << "\n                                                                                                                                     1                              " ;
    cout << "\n                                                                                                                                     2                              " ;
    cout << "\n                                                                                                                                     3                              " ;
    cout << "\n                                                                                                                                     4                              " ;
    cout << "\n                                                                                                                                     5                              " ;
    cout << "\n                                                                                                                                     6                              " ;
    cout << "\n                                                                                                                                     7                              " ;
    cout << "\n                                                                                                                                     8                              " ;
    cout << "\n                                                                                                                                     9                              " ;
    cout << "\n                                                                                                                                    10                              " ;
    
    
    PlacePlayer(BoardPlr);
    //StartBoard(BoardPlr);
    
    PrintBoard(BoardPlr,false);
   // PrintInstruction();
    //PrintBoard(BoardCom,true);
    
    
    
    
    for(int i=0; i< 5; i++)
    {
        Fire();
        cout << "\n" << endl;
        PrintBoard(BoardCom, true);
        PrintInstruction();
        PrintBoard(BoardPlr, false);
    }
    
    
    
    
    
    
}






















































