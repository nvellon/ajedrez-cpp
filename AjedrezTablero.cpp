#include "Ajedrez.h"

Ajedrez::Tablero::Tablero()
{
	_anchoCelda = 0;
	_largoCelda = 0;
	_x = 0;
	_y = 0;

	crearGrilla();
	crearRotulos();
}

Ajedrez::Tablero::~Tablero()
{
	// Nada para hacer
}

void Ajedrez::Tablero::crearGrilla()
{
	Grafica::Imagen* fondo = new Grafica::Imagen("img\\tablero_gris.gif", 470, 470);
	
	fondo->setX(50);
	fondo->setY(60);

	agregar(fondo);
}

void Ajedrez::Tablero::crearGrilla()
{
	char* rotuloX = new char[2];
	rotuloX[0] = '1';
	rotuloX[1] = '\0';

	char* rotuloY = new char[2];
	rotuloY[0] = 'A';
	rotuloY[1] = '\0';

	int xIni = getXInicial(wWidth) - (_anchoCelda / 2);
	int yIni = getYInicial(wHeight) - (_largoCelda / 2);

	int x = xIni + _anchoCelda;
	int y = yIni + _largoCelda;

	for (int i = 0; i < CELDAS_POR_LADO; i++)
	{
		outtextxy(x, yIni, &_rotuloX[0]);
		outtextxy(xIni, y, &_rotuloY[0]);

		_rotuloX[0]++;
		_rotuloY[0]++;

		x += _anchoCelda;
		y += _largoCelda;
	}
}

void Ajedrez::Tablero::setX(int x)
{
	_x = x;
}

int Ajedrez::Tablero::getX()
{
	return _x;
}

void Ajedrez::Tablero::setY(int x)
{
	_x = x;
}

int Ajedrez::Tablero::getY()
{
	return _x;
}

int Ajedrez::Tablero::getXInicial(int wWidth)
{
	return (wWidth / 2) - ((CELDAS_POR_LADO * _anchoCelda) / 2);
}

int Ajedrez::Tablero::getYInicial(int wHeight)
{
	return (wHeight / 2) - ((CELDAS_POR_LADO * _largoCelda) / 2);
}