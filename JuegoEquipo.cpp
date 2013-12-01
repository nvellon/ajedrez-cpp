#include "Juego.h"

Juego::Equipo::Equipo(char* nombre)
{
	_nombre = nombre;
}

Juego::Equipo::~Equipo()
{
	delete _nombre;
}