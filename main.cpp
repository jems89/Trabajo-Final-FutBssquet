#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "jugador.h"
#include "Aro.h"
#include "Pelota.h"
#include<ctime>
#include<cstdlib>

using namespace sf;

int main()
{  ///inicializacion de la ventana
    RenderWindow window(VideoMode(900, 600), "Tiros Al Aro");
    
    window.setFramerateLimit(80);
   // View view(FloatRect(600.f, 600.f, 600.f, 600.f));
    SoundBuffer musicadefondo;
    musicadefondo.loadFromFile("audio/musicaFondo.flac");
    
    ///un canal para reproducir
    Sound sonido;
    sonido.setBuffer(musicadefondo);
    sonido.play();
    /////////////////////
   //texto
    
    // set the text style
    //text.setStyle(Text::Bold | Text::Underlined);
    Font font;
    font.loadFromFile("fonts/WallNotes.otf");
    Text texto;
    texto.setFont(font);
   

    Font letra;
    letra.loadFromFile("fonts/WallNotes.otf");
    Text titulo;
    titulo.setFont(letra);


    

    Sprite FondoDePantalla;
    Texture textura;
    textura.loadFromFile("img/fondegrande1.jpg");
    FondoDePantalla.setTexture(textura);



    
    jugador Jugador;
    Pelota pelotade5;
    Aro basquet;

    basquet.respawn();

    

    int puntos = 0;
    while (window.isOpen())
    {
        //readImput actualizar los estados de los perifericos
        //leer la cola de mensajes
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //CMD - Joy
        // Limpiamos la pantalla
        
        
        Jugador.update();
        pelotade5.update();
        basquet.update();/// llama a la funcion update donde estan todas las validaciones para que el personaje no salga.
        if (Jugador.isCollision(pelotade5)) {
            pelotade5.respawn();
           puntos++;
           texto.setPosition(200, 0);
           texto.setString(std::to_string(puntos));
           texto.setFillColor(Color::Green);
           texto.setCharacterSize(35);
           //texto.getTransform();

        }
        else {
            
            texto.setPosition(350, 0);
            texto.setString(std::to_string(puntos));
            texto.setFillColor(Color::Blue);
            texto.setCharacterSize(60);
        
        
        }
       
       
       titulo.setPosition(0,0);
       
       titulo.setString(" PUNTOS:");
       titulo.setFillColor(Color::Black);
       titulo.setCharacterSize(65);
       window.clear();
       window.draw(FondoDePantalla);
       /*Color(180, 200, 255)*/
       window.draw(texto);
       window.draw(titulo);
       //window.draw(basquet);
       window.draw(Jugador);
       window.draw(pelotade5);
       
        
        
        //window.draw(PrimerPie);
        window.display();
    }

    return 0;
}