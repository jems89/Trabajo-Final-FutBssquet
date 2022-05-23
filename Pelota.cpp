#include "Pelota.h"

Pelota::Pelota()
{
	ImagenDePelota1.loadFromFile("img/pelota10.png");
	PelotaDeFutbol.setTexture(ImagenDePelota1);
	movimiento= { 1,1 };
	velocidad = 8;
	PelotaDeFutbol.setPosition(370, 500);
}

void Pelota::update()
{
	
	
	

	/*if (Keyboard::isKeyPressed(Keyboard::Left))
	{
	PelotaDeFutbol.move(movimiento.x , 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) 
	{
		PelotaDeFutbol.move(0,movimiento.y);
	
	}*/

	if (PelotaDeFutbol.getPosition().x < 200) {
		//PelotaDeFutbol.setPosition(0, PelotaDeFutbol.getPosition().y);
		movimiento.x = -movimiento.x;
	}
	if (PelotaDeFutbol.getPosition().y < 0) {
		//PelotaDeFutbol.setPosition(PelotaDeFutbol.getPosition().x, 0);
		//_sprite.scale(1, 1);
		movimiento.y = -movimiento.y;
	}


	if (PelotaDeFutbol.getPosition().x + PelotaDeFutbol.getGlobalBounds().width > 600) {
		//PelotaDeFutbol.setPosition(800 - PelotaDeFutbol.getGlobalBounds().width, PelotaDeFutbol.getPosition().y);
		movimiento.x = -movimiento.x;
	}


	if (PelotaDeFutbol.getPosition().y + PelotaDeFutbol.getGlobalBounds().height > 600) {
		PelotaDeFutbol.setPosition(PelotaDeFutbol.getPosition().x, 600 - PelotaDeFutbol.getGlobalBounds().height);
		// _sprite.scale(-1, 1);
		movimiento.y = -movimiento.y;
	}
	
	
}

void Pelota::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(PelotaDeFutbol, states);
}

FloatRect Pelota::getBounds() const
{
	return PelotaDeFutbol.getGlobalBounds();
}

void Pelota::respawn()
{
	PelotaDeFutbol.setPosition(std::rand() % 600 + PelotaDeFutbol.getGlobalBounds().width,std::rand() % 400 + PelotaDeFutbol.getGlobalBounds().height);
	PelotaDeFutbol.setPosition(PelotaDeFutbol.move + PelotaDeFutbol.getGlobalBounds().width, std::rand() % 400 + PelotaDeFutbol.getGlobalBounds().height);
	//PelotaDeFutbol.move(movimiento.x, movimiento.y);
}
