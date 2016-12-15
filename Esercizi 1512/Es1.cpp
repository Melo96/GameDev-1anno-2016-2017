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

class Tank
{
    private:
    
    int m_Health = 100;
    int m_Fuel = 100;
    int m_Ammo = 100;
    bool m_Alive = true;
    
    
    public:
    void Check_Dead();
    
    void Status();
    
    void Patrol();
    
    void Attack();

    void Refuel_Reparation();
    
    
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
    
        m_Health -= (distance * 2);
    
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
    
        m_Health -= (strenght * 7);
    
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
    
        m_Health += (supplying * 7);
    
        m_Fuel += (supplying * 3);
        
        m_Ammo += (supplying * 7);
        
        Check_Dead();
        
        if(m_Alive == true)
        {
            Value -= 5;
        }
    }
    
    else
    {
        cout << "\nThis Tank is down" << endl;
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
        cout << "\nScegli tra le missioni proposte:\n1)Pattugliamento\n2)Attacca postazione nemica\n3)Rifornimento e riparazione." << endl;
    
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
            
            default:
                break;
        }
    }
 

    
}
