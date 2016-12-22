//
//  main.cpp
//  Es1_15122016
//
//  Created by Carmelo Mammana on 15/12/16.
//  Copyright © 2016 Carmelo Mammana. All rights reserved.
//

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int Value = 0;
int Death = 0;
const int tank = 5;

class Tank
{
private:
    
    //int id;
    
    int m_Health = 100;
    int m_Fuel = 100;
    int m_Ammo = 100;
    
    bool m_Alive = true;
    
    bool E = false;
    bool A = false;
    bool S = false;
    
    
public:
    
    void Check_Dead();
    
    void Status();
    
    void Patrol();
    
    void Attack();
    
    void Refuel_Reparation();
    
    //int Check_Up_E(Tank t);
    
    int Up_Engine();
    
    int Up_Armor();
    
    int Up_Shell();
    
    
    
    
};


void Tank::Check_Dead()
{
    if(m_Health <= 0)
    {
        m_Alive = false;
        Death += 1;
    }
    
    else if(m_Fuel <= 0)
    {
        m_Alive = false;
        Death += 1;
    }
    
    else if(m_Ammo <= 0)
    {
        m_Alive = false;
        Death += 1;
    }
}

void Tank::Status()
{
    if(m_Alive == true)
    {
        cout << " \n\tHealth: " << m_Health << " \n\tFuel: " << m_Fuel << " \n\tAmmo: " << m_Ammo << endl;
        
        if((E == true)|| (A == true) || (S == true))
        {
            cout << "Upgrade attivi:";
            if(E == true) cout << "\n\tEngine Upgrade\n"<< endl;
            
            if(A == true) cout << "\n\tArmor Upgrade\n"<< endl;
            
            if(S == true) cout << "\n\tShell Upgrade\n"<< endl;
                
        }
        
        else cout << "\n\tnon dispone di Upgrade\n" << endl ;
        
    }
    
    else
    {
        cout << " \nis down" << endl;
    }
}


void Tank::Patrol()
{
    
    if(m_Alive == true)
    {
        
        int distance = (rand() % (3)) +2;
        
        if(A == true)
        {
            m_Health -= distance;
        }
        else
        m_Health -= (distance * 2);
        
        if(E == true)
        {
            m_Fuel -= (distance * 4);
        }
        else
        m_Fuel -= (distance * 8);
        
        
        m_Ammo -= (distance * 2);
        
        Check_Dead();
        
        if(m_Alive == true)
        {
            Value += 1;
        }
        
    }
    
    else
    {
        cout << "\nThis Tank is down" << endl;
    }
}


void Tank::Attack()
{
    if(m_Alive == true)
    {
        
        int strenght = (rand() % (3)) +2;
        
        if(A == true)
        {
            m_Health -= (strenght *7)/2;
        }
        else
        m_Health -= (strenght * 7);
        
        
        if(E == true)
        {
            m_Fuel -= (strenght * 3)/2;
        }
        else
        m_Fuel -= (strenght * 3);
        
        m_Ammo -= (strenght * 7);
        
        Check_Dead();
        
        if(m_Alive == true)
        {
            Value += 2;
        }
        
    }
    
    else
    {
        cout << "\nThis Tank is down" << endl;
    }
    
}


void Tank::Refuel_Reparation()
{
    if(m_Alive == true)
    {
        
        int supplying = (rand() % (3)) +2;
        
        if(S == true)
        {
            m_Health += (supplying * 7)*2;
            
            m_Fuel += (supplying * 3)*2;
            
            m_Ammo += (supplying * 7)*2;
            
        }
        
        else
        {
            m_Health += (supplying * 7);
        
            m_Fuel += (supplying * 3);
        
            m_Ammo += (supplying * 7);
        }
        
        Check_Dead();
        
        if(m_Alive == true)
        {
            int tot = tank - Death;
            Value =Value - ( 1 * tot);
        }
    }
    
    else
    {
        cout << "\nThis Tank is down" << endl;
    }
    
}




int Tank::Up_Engine()
{
    if((Value > 10) && (E == false) && (m_Alive == true))
    {
        Value -= 10;
        E = true;
        cout << "\nEngine Upgrade applicato a" << flush;
        return 1;
    }
    
    else if (Value < 10)
    {
        cout << "\nNon hai abbastanza Valore per acquistare l'Upgrade" << endl;
        
        return -1;
    }
    
    else
    {
        return 0;
    }
}

int Tank::Up_Armor()
{
    if((Value > 20) && (A == false) && (m_Alive == true))
    {
        Value -= 20;
        A = true;
        cout << "\nArmor Upgrade applicato a" << flush;
        return 1;
    }
    
    else if (Value < 20)
    {
        cout << "\nNon hai abbastanza Valore per acquistare l'Upgrade" << endl;
        
        return -1;
    }
    
    else
    {
        return 0;
    }
}

int Tank::Up_Shell()
{
    if((Value > 30) && (S == false) && (m_Alive == true))
    {
        Value -= 30;
        S = true;
        cout << "\nEngine Upgrade applicato a" << flush;
        return 1;
    }
    
    else if (Value < 30)
    {
        cout << "\nNon hai abbastanza Valore per acquistare l'Upgrade" << endl;
        
        return -1;
    }
    
    else
    {
        return 0;
    }
}






int main()
{
    srand(time(NULL));
    
    
    Tank Tiger_1;
    cout << "\n\tStatus Tiger 1:" << flush ;
    Tiger_1.Status();
    
    Tank Tiger_2;
    cout << "\n\tStatus Tiger 2:" << flush ;
    Tiger_2.Status();
    
    Tank Tiger_3;
    cout << "\n\tStatus Tiger 3:" << flush ;
    Tiger_3.Status();
    
    Tank Tiger_4;
    cout << "\n\tStatus Tiger 4:" << flush ;
    Tiger_4.Status();
    
    Tank Tiger_5;
    cout << "\n\tStatus Tiger 5:" << flush ;
    Tiger_5.Status();
    
    
    int choice;
    
    cout << "\n\n\tSei il capo di una squadra di 5 Tank.Scegli la missione da far svolgere alla tua squadra." << endl;
    while((Value < 100) && (Death < 5))
    {
        cout << "\nScegli tra le missioni proposte:\n1)Pattugliamento\n2)Attacca postazione nemica\n3)Rifornimento e riparazione.\nOppure selezione degli upgrade, che sarà applicato al primo Tank vivo che non ne dispone:\n4)Engine Upgrade\n5)Armor Upgrade\n6)Shell Upgrade." << endl;
        
        cin >> choice;
        
        
        switch (choice)
        {
            case 1:
                Tiger_1.Patrol();
                cout << "\nStatus Tiger 1:" << flush ;
                Tiger_1.Status();
                
                Tiger_2.Patrol();
                cout << "\nStatus Tiger 2:" << flush ;
                Tiger_2.Status();
                
                Tiger_3.Patrol();
                cout << "\nStatus Tiger 3:" << flush ;
                Tiger_3.Status();
                
                Tiger_4.Patrol();
                cout << "\nStatus Tiger 4:" << flush ;
                Tiger_4.Status();
                
                Tiger_5.Patrol();
                cout << "\nStatus Tiger 5:" << flush ;
                Tiger_5.Status();
                
                cout << "\n\tScore: " << Value << endl;
                cout << "\n\tDeath: " << Death << endl;
                
                break;
                
            case 2:
                Tiger_1.Attack();
                cout << "\nStatus Tiger 1:" << flush ;
                Tiger_1.Status();
                
                Tiger_2.Attack();
                cout << "\nStatus Tiger 2:" << flush ;
                Tiger_2.Status();
                
                Tiger_3.Attack();
                cout << "\nStatus Tiger 3:" << flush ;
                Tiger_3.Status();
                
                Tiger_4.Attack();
                cout << "\nStatus Tiger 4:" << flush ;
                Tiger_4.Status();
                
                Tiger_5.Attack();
                cout << "\nStatus Tiger 5:" << flush ;
                Tiger_5.Status();
                
                cout << "\n\tScore: " << Value << endl;
                cout << "\n\tDeath: " << Death << endl;
                
                break;
                
            case 3:
                Tiger_1.Refuel_Reparation();
                cout << "\nStatus Tiger 1:" << flush ;
                Tiger_1.Status();
                
                Tiger_2.Refuel_Reparation();
                cout << "\nStatus Tiger 2:" << flush ;
                Tiger_2.Status();
                
                Tiger_3.Refuel_Reparation();
                cout << "\nStatus Tiger 3:" << flush ;
                Tiger_3.Status();
                
                Tiger_4.Refuel_Reparation();
                cout << "\nStatus Tiger 4:" << flush ;
                Tiger_4.Status();
                
                Tiger_5.Refuel_Reparation();
                cout << "\nStatus Tiger 5:" << flush ;
                Tiger_5.Status();
                
                cout << "\n\tScore: " << Value << endl;
                cout << "\n\tDeath: " << Death << endl;
                
                break;
                
            case 4:
                int e;
                
                e = Tiger_1.Up_Engine();
                if(e == 1)
                {
                    cout << " Tiger 1" << endl;
                    cout << "\nStatus Tiger 1:" << flush ;
                    Tiger_1.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                }
                
                e = Tiger_2.Up_Engine();
                if(e == 1)
                {
                    cout << " Tiger 2" << endl;
                    cout << "\nStatus Tiger 2:" << flush ;
                    Tiger_2.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                }
                
                e = Tiger_3.Up_Engine();
                if(e == 1)
                {
                    cout << " Tiger 3" << endl;
                    cout << "\nStatus Tiger 3:" << flush ;
                    Tiger_3.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                }
                
                e = Tiger_4.Up_Engine();
                if(e == 1)
                {
                    cout << " Tiger 4" << endl;
                    cout << "\nStatus Tiger 4:" << flush ;
                    Tiger_4.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                }
                
                e = Tiger_5.Up_Engine();
                if(e == 1)
                {
                    cout << " Tiger 5" << endl;
                    cout << "\nStatus Tiger 5:" << flush ;
                    Tiger_5.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                }
                
                
                
            case 5:
                int a;
                
                a = Tiger_1.Up_Armor();
                if(a == 1)
                {
                    cout << " Tiger 1" << endl;
                    cout << "\nStatus Tiger 1:" << flush ;
                    Tiger_1.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                }
                
                a = Tiger_2.Up_Armor();
                if(a == 1)
                {
                    cout << " Tiger 2" << endl;
                    cout << "\nStatus Tiger 2:" << flush ;
                    Tiger_2.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                    
                }
                
                a = Tiger_3.Up_Armor();
                if(a == 1)
                {
                    cout << " Tiger 3" << endl;
                    cout << "\nStatus Tiger 3:" << flush ;
                    Tiger_3.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                    
                }
                
                a = Tiger_4.Up_Armor();
                if(a == 1)
                {
                    cout << " Tiger 4" << endl;
                    cout << "\nStatus Tiger 4:" << flush ;
                    Tiger_4.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                    
                }
                
                a = Tiger_5.Up_Armor();
                if(a == 1)
                {
                    cout << " Tiger 5" << endl;
                    cout << "\nStatus Tiger 5:" << flush ;
                    Tiger_5.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                    
                }
                
                
                
            case 6:
                int s;
                
                s = Tiger_1.Up_Shell();
                if(s == 1)
                {
                    cout << " Tiger 1" << endl;
                    cout << "\nStatus Tiger 1:" << flush ;
                    Tiger_1.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                }
                
                s = Tiger_2.Up_Shell();
                if(s == 1)
                {
                    cout << " Tiger 2" << endl;
                    cout << "\nStatus Tiger 2:" << flush ;
                    Tiger_2.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                    
                }
                
                s = Tiger_3.Up_Shell();
                if(s == 1)
                {
                    cout << " Tiger 3" << endl;
                    cout << "\nStatus Tiger 3:" << flush ;
                    Tiger_3.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                    
                }
                
                s = Tiger_4.Up_Shell();
                if(s == 1)
                {
                    cout << " Tiger 4" << endl;
                    cout << "\nStatus Tiger 4:" << flush ;
                    Tiger_4.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                    
                }
                
                s = Tiger_5.Up_Shell();
                if(s == 1)
                {
                    cout << " Tiger 5" << endl;
                    cout << "\nStatus Tiger 5:" << flush ;
                    Tiger_5.Status();
                    cout << "\n\tScore: " << Value << endl;
                    cout << "\n\tDeath: " << Death << endl;
                    break;
                    
                }
                
                
                
                
                
                
            default:
                break;
        }
    }
    
    
    
}
