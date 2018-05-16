#include <iostream>
#include "Plansza.hh"
#include "Gra.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;


 int main()
 {

    Plansza x;
    Gra gra;
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
        gra.opoznienie(clock);
        gra.wylaczanieGry(oknoAplikacji);
        gra.plansza(oknoAplikacji, x.getPole(),x.getBicie()  );
        
        }

 
 

            








    }
    
     

 }
 
 
