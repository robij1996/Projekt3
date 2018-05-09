#include <iostream>
#include "Plansza.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;


 int main()
 {

    Plansza x;

    RenderWindow oknoAplikacji( VideoMode( SZEROKOSC, DLUGOSC ), "Kolko Krzyzyk" );
    Clock clock;
    
    while( oknoAplikacji.isOpen() )
    {
        x.opoznienie(clock);
        x.wylaczanieGry(oknoAplikacji);
        x.stronaStartowa(oknoAplikacji);
        

            








    }
    
     

 }
 
 
