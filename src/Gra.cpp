#include "Gra.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>




using namespace std;
using namespace sf;


Gra::Gra()
{
    for(int i = 0; i < 15; i++)
        for(int k = 0; k < 15; k++)
            tab[i][k] = 0;

}

void Gra::opoznienie(Clock zegar)
{
  const float timeStep = 1 / 60.f;
  while(zegar.getElapsedTime().asSeconds() < timeStep);
  sleep(milliseconds(100));
  zegar.restart();
}

void Gra::wylaczanieGry(RenderWindow &oknoAplikacji)
{
    Event zdarzenie;
    while( oknoAplikacji.pollEvent( zdarzenie ) )
    {
      if( zdarzenie.type == Event::Closed )
      oknoAplikacji.close();
    }
}

void Gra::przypisanieWielkosci(int pole, int bicie)
{
    wielkoscPola = pole;
    iloscBic = bicie;
}

void  Gra::tworzenieLini(RenderWindow &oknoAplikacji)
{
    RectangleShape liniaPionowa, liniaPozioma;
    Font font;
    font.loadFromFile( "arial.ttf" );

    liniaPionowa.setSize(sf::Vector2f(0, 600));
    liniaPionowa.setOutlineColor(sf::Color::Black);
    liniaPionowa.setOutlineThickness(1);

    liniaPozioma.setSize(sf::Vector2f(600, 0));
    liniaPozioma.setOutlineColor(sf::Color::Black);
    liniaPozioma.setOutlineThickness(1);



    for(int i = 1; i <= wielkoscPola - 1; i++)
    {
        int zmienna = DLUGOSC/wielkoscPola;
        liniaPionowa.setPosition(i*zmienna, 0);
        oknoAplikacji.draw(liniaPionowa);

        liniaPozioma.setPosition(0, i*zmienna);
        oknoAplikacji.draw(liniaPozioma);

    }


}

void Gra::wstawianieZnakowPrzezCzlowieka(RenderWindow &oknoAplikacji)
{
    float Mx = Mouse::getPosition(oknoAplikacji).x;
    float My = Mouse::getPosition(oknoAplikacji).y;
    Font font;
    font.loadFromFile( "arial.ttf" );



    if(ruchUzytkownika == 1)
    for(int i = 0; i < wielkoscPola; i++)
        if((Mx > i*(DLUGOSC/wielkoscPola) && Mx < i*(DLUGOSC/wielkoscPola) + DLUGOSC/wielkoscPola )  )
            for(int k = 0; k < wielkoscPola; k++)
            if( (My > k*(SZEROKOSC/wielkoscPola) && My < k*(SZEROKOSC/wielkoscPola) + SZEROKOSC/wielkoscPola))

        if( Mouse::isButtonPressed( Mouse::Left ) )
            {
                tab[i][k] = -1;
                ruchUzytkownika = 0;
                ruchKomputera = 1;
                iloscRuchow++;
                
                
                /*
                Text tekst1( "X", font, DLUGOSC/wielkoscPola );
                cout<<i<<" "<<k<<endl;
                tekst1.setPosition( i*(DLUGOSC/wielkoscPola), k*(SZEROKOSC/wielkoscPola) );
                tekst1.setColor( sf::Color::Black );
                oknoAplikacji.draw(tekst1);*/
            }

    for(int i = 0; i < wielkoscPola; i++)
        for(int k = 0; k < wielkoscPola; k++)
            if(tab[i][k] == -1)
            {
                Text tekst1( "X", font, DLUGOSC/wielkoscPola );
                //cout<<i<<" "<<k<<endl;
                tekst1.setPosition( i*(DLUGOSC/wielkoscPola), k*(SZEROKOSC/wielkoscPola) );
                tekst1.setColor( sf::Color::Black );
                oknoAplikacji.draw(tekst1);

            

            }
/*
 for (int a = 0; a < wielkoscPola; ++a)
    {
        for (int b = 0; b < wielkoscPola; ++b)
            cout << tab[b][a] << " ";
        cout << "\n";
    }*/
        


}

void Gra::wstawianieZnakowPrzezKomputer(RenderWindow &oknoAplikacji)
{
    Font font;
    font.loadFromFile( "arial.ttf" );
    srand( time( NULL ) );

    if(ruchKomputera == 1)
    {
        int i = (rand() % wielkoscPola);
        int k = (rand() % wielkoscPola );
        //cout<<i<<"  "<<k<<endl;

        if(tab[i][k] == 0)
        {
            tab[i][k] = 1;
            ruchUzytkownika = 1;
            ruchKomputera = 0;
            iloscRuchow++;
            
            
        }


    }
        for(int i = 0; i < wielkoscPola; i++)
        for(int k = 0; k < wielkoscPola; k++)
            if(tab[i][k] == 1)
            {
                Text tekst1( "O", font, DLUGOSC/wielkoscPola );
                tekst1.setPosition( i*(DLUGOSC/wielkoscPola), k*(SZEROKOSC/wielkoscPola) );
                tekst1.setColor( sf::Color::Black );
                oknoAplikacji.draw(tekst1);

            }


   
    

    
            


}

bool Gra::zabezpiecznie (int i, int k)
{
    if( ( (i + iloscBic) <= wielkoscPola) && ( (k + iloscBic) <= wielkoscPola) )
        return true;
    else
        return false;


}


//funkcja sprawdzajaca czy jest remis 
bool Gra::remis()
{
    for(int i = 0; i < wielkoscPola; i++)
        for(int k = 0; k < wielkoscPola; k++)
            if(tab[i][k]==0)
                return false;
    return true;

}

int Gra::sprawdzenieWygranej()
{
    
    //sprawdzanie wygranej 
    for(int i = 0; i < wielkoscPola; i++)
        for(int  k = 0; k < wielkoscPola; k++)
            {  
                
                     //dla gracza
                     // w poziomie
                    for(int l = 0; l < iloscBic; l++)
                    {      
                        
                        if(tab[i + l][k] == -1)
                        {
                            
                                if(l == iloscBic - 1 )
                                    return -10;
                            
                        }
                        else
                        break;

                    }

                    // w pionie
                    for(int l = 0; l < iloscBic; l++)
                    {
                       if(tab[i][k + l] == -1)
                        {
                            if(l == iloscBic - 1 )
                                    return -10;
                        }
                        else
                        break;


                    }

                    // na skos 
                    for(int l = 0; l < iloscBic; l++)
                    {
                       if(tab[i + l][k + l] == -1)
                        {
                            if(l == iloscBic - 1 )
                                    return -10;
                        }
                        else
                        break;
                    }


                    // drugi skos 
                    for(int l = 0; l < iloscBic; l++)
                    {
                       if(tab[i + l][k - l] == -1)
                        {
                            if(l == iloscBic - 1 )
                                    return -10;
                        }
                        else
                        break;
                    }



                    // dla AI 
                    for(int l = 0; l < iloscBic; l++)
                    {      
                        
                        if(tab[i + l][k] == 1)
                        {
                            
                                if(l == iloscBic - 1 )
                                    return 10;
                            
                        }
                        else
                        break;

                    }

                    // w pionie
                    for(int l = 0; l < iloscBic; l++)
                    {
                       if(tab[i][k + l] == 1)
                        {
                            if(l == iloscBic - 1 )
                                    return 10;
                        }
                        else
                        break;


                    }

                    // na skos 
                    for(int l = 0; l < iloscBic; l++)
                    {
                       if(tab[i + l][k + l] == 1)
                        {
                            if(l == iloscBic - 1 )
                                    return 10;
                        }
                        else
                        break;
                    }


                    // drugi skos 
                    for(int l = 0; l < iloscBic; l++)
                    {
                       if(tab[i + l][k - l] == 1)
                        {
                            if(l == iloscBic - 1 )
                                    return 10;
                        }
                        else
                        break;
                    }
            }

    
 
return 0;

}


void Gra::plansza(RenderWindow &oknoAplikacji, int pole, int bicie)
{
    przypisanieWielkosci(pole, bicie);

    oknoAplikacji.clear( Color::White );

    tworzenieLini(oknoAplikacji);

    wstawianieZnakowPrzezCzlowieka(oknoAplikacji);

    wstawianieZnakowPrzezKomputer(oknoAplikacji);

    if(sprawdzenieWygranej() == -10)
                {
                    cout<<"wygrana czlowieka"<<endl;
                }
    if(sprawdzenieWygranej() == 10)
        {
            cout<<"wygrana komputera"<<endl;
        }
    if(remis())
        cout<<"remis!!"<<endl;

        
    


    












    oknoAplikacji.display();

}