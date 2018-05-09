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
    
    int wielkoscPola = 0; //zmienna ktora przyjmuje wartosc wielkosci pola 
    int danaDoPola = 0;   // zmienna pomocnica w obliczeniu wielkosci pola 
    int iloscBic = 0;     // zmienna ktora przyjmuje ilosc figur w rzedzie do zbicia
    int danaDoBic = 0;    // pomocnicza to wyznaczenia ilosci bic 
    int wcisniecieMyszki = 0;   //pomocnica zwiazana z myszka
    Font font;
    
    public:
    void konstruktorFont();
    void opoznienie(Clock);
    void wylaczanieGry(RenderWindow&);
    void stronaStartowa(RenderWindow&);
    void daneWielkosc(RenderWindow&);
    void wygladPolaStartowego(RenderWindow &);
    void daneBic(RenderWindow &);
    void przejscieDoGry(RenderWindow &, int &);


    
 };

 #endif
