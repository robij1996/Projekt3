#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{   
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 400, 400 ), "Kolko Krzyzyk" );
    sf::Clock clock;
    const float timeStep = 1 / 60.f;
    while( oknoAplikacji.isOpen() )
    {

    while(clock.getElapsedTime().asSeconds() < timeStep)
	sf::sleep(sf::milliseconds(20));
    clock.restart();


sf::Font font;
font.loadFromFile( "arial.ttf" );

sf::Text tekst( "NIC", font, 50 );
tekst.setPosition( 10, 10 );
tekst.setColor( sf::Color::Red );
oknoAplikacji.draw( tekst );


    
   
    
    oknoAplikacji.display(); 
    
    
        sf::Event zdarzenie;
        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                 oknoAplikacji.close();
             
        }

            float Mx = sf::Mouse::getPosition(oknoAplikacji).x;
            float My = sf::Mouse::getPosition(oknoAplikacji).y;
            
            if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
            {
                        //cout<<"Klik"<<endl;

            
            }


  /*Wczytywanie znaków z klawiatury !!!*/                  
  if (zdarzenie.type == sf::Event::TextEntered)
{
    if (zdarzenie.text.unicode < 128)
        {
        char zmienna =  static_cast<char>(zdarzenie.text.unicode);
        std::cout << zmienna  << std::endl;
        int x = atoi(&zmienna);
        cout<<x<<endl;

        }
}
  
   
        

    }
    return 0;
}