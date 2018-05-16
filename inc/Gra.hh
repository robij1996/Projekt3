#ifndef GRA_HH
#define GRA_HH
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

static unsigned int DLUGOSC = 600;
static unsigned int SZEROKOSC = 600;



class Gra
 {  

     int wielkoscPola;
     int iloscBic;
     int tab[15][15];
     int ruchUzytkownika = 1;
     int ruchKomputera = 0 ;
     int iloscRuchow = 0;
      


     public:

     Gra();
     void wylaczanieGry(RenderWindow &);
     void opoznienie(Clock);
     void plansza(RenderWindow &, int, int);
     void przypisanieWielkosci(int , int );
     void tworzenieLini(RenderWindow &);
     void wstawianieZnakowPrzezCzlowieka(RenderWindow &);
     void wstawianieZnakowPrzezKomputer(RenderWindow &);
     int sprawdzenieWygranej();
     bool zabezpiecznie (int i, int k);
     bool remis();
    
   

    
 };

 #endif
