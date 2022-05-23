#pragma once
#include<SFML/Graphics.hpp>
#include"colision.h"
using namespace sf;

class Pelota : public Drawable, public colision
{
private:
    Sprite PelotaDeFutbol;
    Texture ImagenDePelota1;
    Vector2f movimiento;
    float velocidad;



public:

    Pelota();
    void update();
    void draw(RenderTarget& target, RenderStates states) const override;
    FloatRect getBounds() const override;
    void respawn();

};