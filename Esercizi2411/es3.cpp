#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

int differenceX(int xcpu, int xuser);
int differenceY(int ycpu, int yuser);

int main()
{
    char grid[10][10];
    srand(3);
    
    int xcpu = 0;
    int ycpu = 0;
    
    int dx = 0;
    int dy = 0;
    
    int x = 0;
    int y = 0;
    char cpu = '.';
    char choice = ' ';
    

        xcpu = rand() % (10);
        ycpu = rand() % (10);
 
    
        grid[xcpu][ycpu] = cpu;
    
    
        
    
        do
        {
            cout << "Inserire riga dove colpire da 0 a 10" << endl;
            cin >> x;
            
            cout << "\nInserire colonna dove colipre da 0 a 10" << endl;
            cin >> y;
        
        
            dx = differenceX(xcpu , x);
            dy = differenceY(ycpu, y);
        
        
            if((dx == 0) && (dy == 0))
            {
                cout << "Hai colpito la nave nemica! Hai vinto\n" << endl;
                cout << "Vuoi rigiocare? Y o N" << endl;
                cin >> choice;
            }
        
            else if((dx == 1)  || (dy == 1))
            {
                cout << "Fuoco" << endl;
            }
        
            else if((dx == 2) || (dy == 2))
            {
                cout << "Fuocherello" << endl;
            }
        
            else if((dx > 2) || (dy > 2))
            {
                cout << "Acqua" << endl;
            }
        
        }
        while(choice != 'N');
    
    
    
    
    
}



int differenceX(int xcpu , int xuser)
{
    int dx=0;
    if(xcpu > xuser)
    {
        dx = xcpu - xuser;
        return dx;
    }
    
    else
    {
        dx = xuser - xcpu;
        return dx;
    }
}



int differenceY(int ycpu , int yuser)
{
    int dy=0;
    if(ycpu > yuser)
    {
        dy = ycpu - yuser;	
        return dy;
    }
    
    else
    {
        dy = yuser - ycpu;
        return dy;
    }
}












