#pragma once
#include<SFML/Graphics.hpp>
#include"colision.h"
using namespace sf;


class jugador: public sf::Drawable , public colision

{ private:
    Sprite _sprite;
    Texture _texture;
    //float x, y;
    //float speed, angle, maxSpeed, acc, dec, turnSpeed;
    float velocidad=0;
   // View view1;
public:
    FloatRect getBounds() const override;
    jugador();
    void update();
    void draw(RenderTarget& target, RenderStates states) const override;
    void setPos(float x, float y);
    void setRot(float r);
    void setAngle(float a);
    void respawn(float x1, float y1, float a);

    
   

};

