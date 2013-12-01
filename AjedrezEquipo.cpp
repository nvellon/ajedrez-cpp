#include "Ajedrez.h"

Ajedrez::Equipo::Equipo(char* nombre):Juego::Equipo(nombre)
{
	//
}

Ajedrez::Equipo::~Equipo()
{
	//
}

void Ajedrez::Equipo::setColor(char color)
{
	_color = color;
}

char Ajedrez::Equipo::getColor()
{
	return _color;
}