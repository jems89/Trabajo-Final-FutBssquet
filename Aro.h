#pragma once

#include<SFML/Graphics.hpp>
#include"colision.h"
using namespace sf;

class Aro: public sf::Drawable ,public colision
{
private:
    Sprite _aro;
    Texture _foto;
    Vector2f vel;
    float velocidad;
    
  
public:

    Aro();
    void update();
    void draw(RenderTarget& target, RenderStates states) const override;
    FloatRect getBounds() const override;
    void respawn();

};