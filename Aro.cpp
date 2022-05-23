#include "Aro.h"

Aro::Aro()
{
	_foto.loadFromFile("img/aroDe.png");
	_aro.setTexture(_foto);
    vel ={0,0};
    _aro.setOrigin(_aro.getGlobalBounds().width / 2,
        _aro.getGlobalBounds().height);
    velocidad = 4;
    
}

void Aro::update()
{

    //_aro.setPosition(350,0);
    _aro.move(vel);
    /*
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        _aro.move(0, -velocidad);
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        _aro.move(0, velocidad);
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        _aro.move(-velocidad, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        _aro.move(velocidad, 0);
    }
    */
    if (_aro.getPosition().x < 0) {
       //_aro.setPosition(0, _aro.getPosition().y);
      vel.x = -vel.x;
    }
    if (_aro.getPosition().y < 0) {
        //_aro.setPosition(_aro.getPosition().x, 0);
        vel.y = -vel.y;
    }

    if (_aro.getPosition().x + _aro.getGlobalBounds().width > 800) {
            //_aro.setPosition(800 - _aro.getGlobalBounds().width, _aro.getPosition().y);
        vel.x = -vel.x;
        }


      if (_aro.getPosition().y + _aro.getGlobalBounds().height > 600) {
           // _aro.setPosition(_aro.getPosition().x, 600 - _aro.getGlobalBounds().height);
            vel.y = -vel.y;
        }
}


    void Aro::draw(RenderTarget& target, RenderStates states) const

    {
    
    
       target.draw(_aro, states);
    

    }

    FloatRect Aro::getBounds() const
    {
        return _aro.getGlobalBounds();
    }

    void Aro::respawn()
    {
        _aro.setPosition(std::rand() % 700 +
            _aro.getGlobalBounds().width,
            std::rand() % 500 + _aro.getGlobalBounds().height);
    }


    /* if (Keyboard::isKeyPressed(Keyboard::Up)) {
        velocidad.y=-4;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        velocidad.y = 4;
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        velocidad.x = -4;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        velocidad.x = 4;
    }

    _aro.move(velocidad);

    if (velocidad.x < 0) { _aro.scale(-1, 1); }
    else if (velocidad.x > 0) { _aro.scale(1,-1); }
    */