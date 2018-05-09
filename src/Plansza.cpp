#include "Plansza.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



using namespace std;
using namespace sf;

void Plansza::opoznienie(Clock zegar)
{
  const float timeStep = 1 / 60.f;
  while(zegar.getElapsedTime().asSeconds() < timeStep)
	sleep(milliseconds(20));
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
  tekstura.loadFromFile( "Start.png" );
  obrazek.setTexture( tekstura );
  obrazek.setPosition(200, 100);
  oknoAplikacji.draw(obrazek);


  Text tekst1( "Podaj wielkosc planszy", font, 20 );
  tekst1.setPosition( 100, 300 );
  tekst1.setColor( sf::Color::Black );
  oknoAplikacji.draw(tekst1);

  Text tekst2( "Podaj ilosc znokow w rzedzie", font, 20 );
  tekst2.setPosition( 100, 400 );
  tekst2.setColor( sf::Color::Black );
  oknoAplikacji.draw(tekst2);


  szerokoscPola.setSize(sf::Vector2f(100, 50));
  szerokoscPola.setOutlineColor(sf::Color::Black);
  szerokoscPola.setOutlineThickness(5);
  szerokoscPola.setPosition(125, 330);
  oknoAplikacji.draw(szerokoscPola);

  szerokoscPola.setPosition(125, 430);
  oknoAplikacji.draw(szerokoscPola);


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



void Plansza::stronaStartowa(RenderWindow &oknoAplikacji)
{
  Event wczytywanie;

  wygladPolaStartowego(oknoAplikacji);
  daneWielkosc(oknoAplikacji);

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
             cout<<iloscBic<<" bicia"<<endl;
             cout<<wielkoscPola<<" pole"<<endl;
            wcisniecieMyszki = 0;
            danaDoPola = 0;
            danaDoBic = 0;
           }
        }
      }
    daneBic(oknoAplikacji);
    

  

  



  oknoAplikacji.display();


}



