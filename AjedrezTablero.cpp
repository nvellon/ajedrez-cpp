#include "Ajedrez.h"

Ajedrez::Tablero::Tablero(int x, int y)
{
	_x = x;
	_y = y;

	crearGrilla();
}

Ajedrez::Tablero::~Tablero()
{
	delete _grilla;
}

void Ajedrez::Tablero::crearGrilla()
{
	_grilla = new Grafica::Imagen("img\\tablero_gris.gif", GRILLA_IMAGEN_ANCHO, GRILLA_IMAGEN_ALTO);
	
	_grilla->setX(_x + SEPARACION_TABLERO_ROTULO_ANCHO);
	_grilla->setY(_y + SEPARACION_TABLERO_ROTULO_ALTO);

	agregar(_grilla);
}

void Ajedrez::Tablero::dibujarRotulos()
{
	int x = _x  + SEPARACION_TABLERO_ROTULO_ANCHO + (GRILLA_IMAGEN_ANCHO_CELDA / 2);
	int y = _y + (SEPARACION_TABLERO_ROTULO_ALTO - 5) + (GRILLA_IMAGEN_ALTO_CELDA / 2);

	char* textoX = new char[2];
    textoX[0] = '1';
    textoX[1] = '\0';

    char* textoY = new char[2];
    textoY[0] = 'A';
    textoY[1] = '\0';

	for (int i = 0; i < CELDAS_POR_LADO; i++)
	{
		outtextxy(x, _y, &textoX[0]);
		outtextxy(_x, y, &textoY[0]);

		x += GRILLA_IMAGEN_ANCHO_CELDA;
		y += GRILLA_IMAGEN_ALTO_CELDA;

		textoX[0]++;
		textoY[0]++;
	}

	delete[] textoX;
	delete[] textoY;
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

void Ajedrez::Tablero::dibujar()
{
	dibujarRotulos();

	Grafica::Composicion::dibujar();
}