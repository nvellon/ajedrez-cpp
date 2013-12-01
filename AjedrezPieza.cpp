#include "Ajedrez.h"

Ajedrez::Pieza::Pieza():Juego::Pieza()
{
	
}

Ajedrez::Pieza::~Pieza()
{
	
}

bool Ajedrez::Pieza::getPuedeSaltar()
{
	return _puedeSaltar;
}
