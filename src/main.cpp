#include <iostream>
#include "Plansza.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;


 int main()
 {

    Plansza x;
    int przejscie = 0;

    RenderWindow oknoAplikacji( VideoMode( SZEROKOSC, DLUGOSC ), "Kolko Krzyzyk" );
    Clock clock;
    
    while( oknoAplikacji.isOpen() )
    {
        if(przejscie == 0)
        {

        x.opoznienie(clock);
        x.wylaczanieGry(oknoAplikacji);
        x.stronaStartowa(oknoAplikacji);
        x.przejscieDoGry(oknoAplikacji, przejscie);

        }
        else
        {
        break;
        }

 
 

            








    }
    
     

 }
 
 
