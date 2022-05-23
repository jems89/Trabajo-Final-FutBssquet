#include "colision.h"

bool colision::isCollision(colision& obj) const  {
	return getBounds().intersects(obj.getBounds());

}
