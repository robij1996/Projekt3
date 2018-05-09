#ifndef PLANSZA_HH
#define PLANSZA_HH
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

static unsigned int DLUGOSC = 600;
static unsigned int SZEROKOSC = 600;



class Plansza
 {
    
    int wielkoscPola = 0;
    int danaDoPola = 0;
    int iloscBic = 0;
    int danaDoBic = 0;
    int wcisniecieMyszki = 0;
    Font font;
    
    public:
    int wymiar;
    void konstruktorFont();
    void opoznienie(Clock);
    void wylaczanieGry(RenderWindow&);
    void stronaStartowa(RenderWindow&);
    void daneWielkosc(RenderWindow&);
    void wygladPolaStartowego(RenderWindow &);
    void daneBic(RenderWindow &);

    
 };

 #endif
