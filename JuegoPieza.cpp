#include "Juego.h"

Juego::Pieza::Pieza():Grafica::Imagen()
{
	// Nada que hacer.
}

Juego::Pieza::~Pieza()
{
	// Nada que hacer.
}

char* Juego::Pieza::getIcono()
{
	return _icono;
}

void Juego::Pieza::setEquipo(Juego::Equipo* equipo)
{
	_equipo = equipo;
}

Juego::Equipo* Juego::Pieza::getEquipo()
{
	return _equipo;
}