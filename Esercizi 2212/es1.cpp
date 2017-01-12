//
//  main.cpp
//  es1_22122016
//
//  Created by Carmelo Mammana on 22/12/16.
//  Copyright © 2016 Carmelo Mammana. All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;

int chance = 0;
bool findDracula = false;

bool turn=true;     //true = turno Van Helsing     false= turno nemici

int start = 1;
int range = (chance / 10);


int win = 0;

class Human
{
private:
    
    int m_Health;
    int m_Will;
    int m_Attack;
    int m_Taunt;
    
    
    
public:
    
    Human(int h, int w, int a, int t);
    void Status();
    void Attack(Human e1, Human e2, Human e3);
    void Attack(Human& e1);
    void Will(Human e1, Human e2, Human e3);
    void Will(Human e1);
    void Hunting();
    void Rest();
    void Battle(Human e1, Human e2, Human e3);
    void Battle(Human e1);
    int Check_Dead();
    
};

Human::Human(int h, int w, int a, int t)
{
    m_Health = h;
    m_Will = w;
    m_Attack = a;
    m_Taunt = t;
}


void Human::Status()
{
    //Visualizza attributi
    
    cout << "\nSalute: " << this->m_Health << "\nVolonta': " << this->m_Will << "\nAttacco: " << this->m_Attack << "\nIntimidazione: "<<  this->m_Taunt << endl;
    
    
}

void Human::Attack(Human e1, Human e2, Human e3)
{
    //Attacco combattimento normale
    int x;
    
    x = rand() % (6);
    
    e1.m_Health = e1.m_Health - (m_Attack + x);
    
    x = rand() % (6);
    
    e2.m_Health = e2.m_Health -(m_Attack + x);
    
    x = rand() % (6);
    
    e3.m_Health = e3.m_Health -(m_Attack + x);
    
    cout << "\nNemico 1:" << endl;
    e1.Status();
    
    cout << "\nNemico 2:" << endl;
    e2.Status();
    
    cout << "\nNemico 3:" << endl;
    e2.Status();
    
    
}

void Human::Attack(Human& e1)
{
    //Attacco combattimento Dracula / Attacco mostri
    
    int x;
    
    x = rand() % (6);
    
    e1.m_Health = e1.m_Health - (this->m_Attack + x);
}

void Human::Will(Human e1, Human e2, Human e3)
{
    //Intimidazione
    
    int x;
    
    x = rand() % (6);
    
    e1.m_Will -= (this->m_Will + x);
    
    x = rand() % (6);
    
    e2.m_Will -= (this->m_Will + x);
    
    x = rand() % (6);
    
    e3.m_Will -= (this->m_Will + x);
    
    cout << "\nNemico 1:" << endl;
    e1.Status();
    
    cout << "\nNemico 2:" << endl;
    e2.Status();
    
    cout << "\nNemico 3:" << endl;
    e2.Status();
}

void Human::Will(Human e1)
{
    //Intimidazione
    
    int x;
    
    x = rand() % (6);
    
    e1.m_Will -= (this->m_Will + x);
}

void Human::Hunting()
{
    //rand per decidere true o false
    int x = rand() % (10) + 1;
    
    if((x <= range) && (x >= start))
    {
        findDracula = true;
        
    }
    
    else
    {
        findDracula = false;
    }
    
    
    if(findDracula == true)     //Se Dracula è trovato parte una battaglia con lui
    {
        cout << "\nEccolo!!E' Dracula!!" << endl;
        Human Dracula(50, 50, 20, 20);
        Battle(Dracula);
    }
    
    else                        //Altrimenti parte una battaglia normale
    {
        cout << "Hai incontrato tre nemici! Di dracula non c'e' traccia" << endl;
        int r = rand() % (2);
        if( r == 0)
        {
            Human Servant1(12, 30, 12, 10);
            Human Servant2(12, 30, 12, 10);
            Human Servant3(12, 30, 12, 10);
            Battle(Servant1, Servant2, Servant3);
            
        }
        
        else
        {
            Human Spectre1(100, 12, 2, 20);
            Human Spectre2(100, 12, 2, 20);
            Human Spectre3(100, 12, 2, 20);
            Battle(Spectre1, Spectre2, Spectre3);
        }
        
    }
}


void Human::Rest()
{
    int random;
    
    random = rand() % (10) + 1;
    
    if(random <= 7)
    {
        int x;
        
        x = rand() % (10) + 5;
        
        m_Health += x;
        m_Will += x;
        
    }
    
    else
    {
        cout << "\nOh no! Mentre ti riposavi tre nemici ti hanno attaccato!!" << endl;
        int r = rand() % (2);
        if( r == 0)
        {
            Human Servant1(12, 30, 12, 10);
            Human Servant2(12, 30, 12, 10);
            Human Servant3(12, 30, 12, 10);
            Battle(Servant1, Servant2, Servant3);
            
        }
        
        else
        {
            Human Spectre1(100, 12, 2, 20);
            Human Spectre2(100, 12, 2, 20);
            Human Spectre3(100, 12, 2, 20);
            Battle(Spectre1, Spectre2, Spectre3);
        }

    }
}

void Human::Battle(Human e1, Human e2, Human e3)
{
    do
    {
        
        cout << "\nVan Helsing:" << endl;
        this->Status();
        /*
        cout << "\nNemico 1:" << endl;
        e1.Status();
        
        cout << "\nNemico 2:" << endl;
        e2.Status();
        
        cout << "\nNemico 3:" << endl;
        e2.Status();*/
        
        
        if(turn == true)
        {
            int c;
            cout << "\n\nE' il turno di Van Helsing, scegli cosa fare:\n1)Attacca\n2)Intimidisci" << endl;
            cin >> c;
            
            
                if((c == 1)&&(turn == true))
                {
                    
                    
                    this-> Attack(e1, e2, e3);  // this -> il chiamante è colui che sta usando la funzione
                    
                    
                    
                    turn = false; //Cambia turno
                    
                }
            
                else if((c == 2)&&(turn == true))
                {

                    cout << "\nVan Helsing:" << endl;
                    this->Status();
                    
                    Will(e1, e2, e3);
                    
                    turn = false; //Cambia turno
                }
            
            
            
        }
        
        else if(turn == false)
        {
            int r = rand() % (2);
            
            if(r == 0) //Attacca
            {
                
                cout << "\nAttaccano i nemici" << endl;
                e1.Attack(*this);
                e2.Attack(*this);
                e3.Attack(*this);
                
                turn = true; //Cambia turno
            }
            
            else
            {
                /*cout << "\nNemico 1:" << endl;
                e1.Status();
                
                cout << "\nNemico 2:" << endl;
                e2.Status();
                
                cout << "\nNemico 3:" << endl;
                e2.Status();*/
                
                
                e1.Will(*this);
                e2.Will(*this);
                e3.Will(*this);
                
                turn = true; //Cambia turno
                
            }
        }
        
    }
    
    while(e1.m_Health >= 0);// && (e2.m_Health <= 0) && (e3.m_Health <= 0)));
    
    if(m_Health != 0)
    {
        chance += 1;
        cout << "\nBATTAGLIA VINTA" << endl;
    }
    
}

void Human::Battle(Human e1)
{
    do
    {
        if(turn)
        {
            int c;
            cout << "E' il turno di Van Helsing, scegli cosa fare:\n1)Attacca\n2)Intimidisci" << endl;
            cin >> c;
  
                if(c == 1)
                {
                    cout << "\nVan Helsing:" << endl;
                    this->Status();
                    
                    Attack(e1);
                    
                    turn = false; //Cambia turno
                    
                }
            
                else if(c == 2)
                {
                    cout << "\nVan Helsing:" << endl;
                    this->Status();
                    
                    Will(e1);
                    
                    turn = false; //Cambia turno
                }

            
        }
        
        else if(!turn)
        {
            int r = rand() % (2);
            
            if(r == 0) //Attacca
            {
                cout << "\nNemico:" << endl;
                e1.Status();
                e1.Attack(*this);
                
                turn = true; //Cambia turno
            }
            
            else
            {
                cout << "\nNemico:" << endl;
                e1.Status();
                e1.Will(*this);
                
                turn = true; //Cambia turno
                
            }
        }
        
    }
    
    while((m_Health == 0) || (e1.m_Health == 0));
    
    if(e1.m_Health == 0)
        win = 1;
        
    
    
}

int Human::Check_Dead()
{

    if(m_Health == 0)
        return 1;
    
    return 0;
}



int main()
{
    srand(time(NULL));
    
    Human VHelsing(100, 100, 10, 10);
    
    cout << "\n\tBenvenuto nella leggendaria caccia di Van Helsing al Conte Dracula!" << endl;
    cout << "\nIl gioco si svolge a turni. Ad ogni turno puoi scegliere se proseguire la caccia nel tentativo di incontrare il Conte Dracula o se riposarti" << endl;
    cout << "\nRiuscirai a sconfiggere Dracula!? " << endl;
    cout << "\n...Good Hunting...Good Luck..." << endl;
    
    do
    {
        
        
        cout << "\nScegli cosa fare:\n1)Caccia\n2)riposati" << endl;
        int scelta;
        
        cin >> scelta;
        
        if(scelta == 1)
        {
            VHelsing.Hunting();
        }
        
        else
        {
            VHelsing.Rest();
        }

    }
    
    while((VHelsing.Check_Dead() == 0) || (win == 0));
  
    
}
































