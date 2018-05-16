#include "Plansza.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



using namespace std;
using namespace sf;



int Plansza::getPole()
{
  return wielkoscPola;
}

int Plansza::getBicie()
{
  return iloscBic;
}

void Plansza::opoznienie(Clock zegar)
{
  const float timeStep = 1 / 60.f;
  while(zegar.getElapsedTime().asSeconds() < timeStep)
	sleep(milliseconds(50));
  zegar.restart();
    
}

void Plansza::wylaczanieGry(RenderWindow &oknoAplikacji)
{
  Event zdarzenie;
  while( oknoAplikacji.pollEvent( zdarzenie ) )
    {
      if( zdarzenie.type == Event::Closed )
      oknoAplikacji.close();
    }
}

void Plansza::konstruktorFont()
{
  font.loadFromFile( "arial.ttf");
}

void Plansza::wygladPolaStartowego(RenderWindow &oknoAplikacji)
{
  oknoAplikacji.clear( Color::White );
  RectangleShape szerokoscPola;

  Font font;
  font.loadFromFile( "arial.ttf" );

  Texture tekstura;
  Sprite obrazek;

  //Start
  if(wielkoscPola > 2 && iloscBic > 2)
  {
    tekstura.loadFromFile( "Start.png" );
    obrazek.setTexture( tekstura );
    obrazek.setPosition(200, 100);
    oknoAplikacji.draw(obrazek);
  }
  else
  {
  Text tekst6( "Nie spelnione warunki, nie mozna uruchimic gry", font, 20 );
  tekst6.setPosition( 50, 50 );
  tekst6.setColor( Color::Red );
  oknoAplikacji.draw(tekst6);

  Text tekst5( "Musi byc wiecej niz 3 pola i bicia", font, 20 );
  tekst5.setPosition( 100, 500 );
  tekst5.setColor( sf::Color::Blue );
  oknoAplikacji.draw(tekst5);

  }

  Text tekst1( "Podaj wielkosc planszy", font, 20 );
  tekst1.setPosition( 100, 300 );
  tekst1.setColor( sf::Color::Black );
  oknoAplikacji.draw(tekst1);

  Text tekst2( "Podaj ilosc znokow w rzedzie", font, 20 );
  tekst2.setPosition( 100, 400 );
  tekst2.setColor( sf::Color::Black );
  oknoAplikacji.draw(tekst2);


  

  //ramki na liczby 
  szerokoscPola.setSize(sf::Vector2f(100, 50));
  szerokoscPola.setOutlineColor(sf::Color::Black);
  szerokoscPola.setOutlineThickness(5);
  szerokoscPola.setPosition(125, 330);
  oknoAplikacji.draw(szerokoscPola);

  szerokoscPola.setPosition(125, 430);
  oknoAplikacji.draw(szerokoscPola);
   
   //ilosc znakow w rzedzie
  string abc = to_string(iloscBic);
  Text tekst3( abc, font, 50 );
  tekst3.setPosition( 130, 425 );
  tekst3.setColor( sf::Color::Black );
  oknoAplikacji.draw(tekst3);

   //wielkosc pola 
  abc = to_string(wielkoscPola);
  Text tekst4( abc, font, 50 );
  tekst4.setPosition( 130, 320 );
  tekst4.setColor( sf::Color::Black );
  oknoAplikacji.draw(tekst4);


}

void Plansza::daneWielkosc(RenderWindow &oknoAplikacji)
{
  Mouse myszka;

  if(myszka.getPosition(oknoAplikacji).x < 230 && myszka.getPosition(oknoAplikacji).x > 120 && myszka.getPosition(oknoAplikacji).y < 480 && myszka.getPosition(oknoAplikacji).y > 430)
    if(myszka.isButtonPressed(myszka.Left))  
    {
      danaDoBic++;
      wcisniecieMyszki++;
    }

}

void Plansza::daneBic(RenderWindow &oknoAplikacji)
{
  Mouse myszka;


  if(myszka.getPosition(oknoAplikacji).x < 230 && myszka.getPosition(oknoAplikacji).x > 120 && myszka.getPosition(oknoAplikacji).y < 384 && myszka.getPosition(oknoAplikacji).y > 326)
    if(myszka.isButtonPressed(myszka.Left))
    {
      danaDoPola++;
      wcisniecieMyszki++;
    }

}
void Plansza::przejscieDoGry(RenderWindow &oknoAplikacji, int &przejscie)
{
    Mouse myszka;
    if(iloscBic > 2 && wielkoscPola > 2)
     if(myszka.getPosition(oknoAplikacji).x < 400 && myszka.getPosition(oknoAplikacji).x > 200 && myszka.getPosition(oknoAplikacji).y < 200 && myszka.getPosition(oknoAplikacji).y > 100)
        if(myszka.isButtonPressed(myszka.Left))
        {
         przejscie++;
        }


}

void Plansza::stronaStartowa(RenderWindow &oknoAplikacji)
{
  Event wczytywanie;

  wygladPolaStartowego(oknoAplikacji);
  daneWielkosc(oknoAplikacji);
  daneBic(oknoAplikacji);

  if(wcisniecieMyszki > 0)
    if (wczytywanie.type == Event::TextEntered)
      {   
        if (wczytywanie.text.unicode < 128)
        {

          char zmienna =  static_cast<char>(wczytywanie.text.unicode);

          if(danaDoPola > 0)
           wielkoscPola = atoi(&zmienna);
 

          if(danaDoBic > 0)
            iloscBic = atoi(&zmienna);
            

          if(danaDoPola || danaDoBic > 0)
           {
            wcisniecieMyszki = 0;
            danaDoPola = 0;
            danaDoBic = 0;
           }
        }
      }

  

  /**/


  oknoAplikacji.display();



}



