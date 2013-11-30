#include "Juego.h"

Juego::Pieza::Pieza()
{
	// Nada que hacer.
}

Juego::Pieza::~Pieza()
{
	// Nada que hacer.
}

void Juego::Pieza::setIcono(char icono)
{
	_icono = icono;
}

char Juego::Pieza::getIcono()
{
	return _icono;
}