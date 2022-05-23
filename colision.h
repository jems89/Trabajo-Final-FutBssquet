#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
class colision {

public:
	virtual FloatRect getBounds() const = 0;
	bool isCollision(colision &col) const;
};