
#include "jugador.h"
#include <cmath>
#include <iostream>

FloatRect jugador::getBounds() const
{
    return _sprite.getGlobalBounds();
}

 jugador::jugador()
{
	_texture.loadFromFile("img/jugador1.png");
	_sprite.setTexture(_texture);
    velocidad = 8;
    //_sprite.setOrigin(0, -450);
    //view1.setSize(200.f, 200.f);
    _sprite.setPosition(2, 500);
}

void jugador::update()
{
    
    //
    
   if (Keyboard::isKeyPressed(Keyboard::Up)) {
        //_sprite.move(3, 500);
        //velocidad.y = -8;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
       //_sprite.move(3, 500);
       // velocidad.y = 8;
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        _sprite.move(-velocidad, 500);
        //velocidad= -8;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
       _sprite.move(velocidad, 500);
       // velocidad = 8;
    }

    //_sprite.move(velocidad);

  if (_sprite.getPosition().x < 0) {
       _sprite.setPosition(0, _sprite.getPosition().y);
       //_sprite.scale(-1, 1);
  }
    if (_sprite.getPosition().y < 0) {
        _sprite.setPosition(_sprite.getPosition().x, 0);
      // _sprite.scale(1, 1);
    }
    

   if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 900) {
       _sprite.setPosition(900 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
       //_sprite.scale(1, 1);
   }


    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height);
       // _sprite.scale(-1, 1);
   }
}

void jugador::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(_sprite, states);
}

void jugador::setPos(float x, float y)
{
        _sprite.setPosition(x, y);
    
}

void jugador::setRot(float r)
{
        _sprite.setRotation(r);
 
}

/*void jugador::setAngle(float a)
{
        angle = a;
}*/

/*void jugador::respawn(float x1, float y1, float a)
{
        x = x1;
        y = y1;
        speed = 0;
        angle = a;
}*/

