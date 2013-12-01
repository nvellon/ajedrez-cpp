#include "Ajedrez.h"

Ajedrez::Casillero::Casillero(Ajedrez::coordTablero coordenada, Ajedrez::coordPantalla puntoInicialTablero)
{
	_coordenada = coordenada;
	_puntoInicialTablero = puntoInicialTablero;
	_pieza = NULL;
	
	calcularCoordenadas();
}

Ajedrez::Casillero::~Casillero()
{
	delete _pieza;
}

void Ajedrez::Casillero::setPieza(Ajedrez::Pieza* pieza)
{
	_pieza = pieza;

	int x = _puntoInicial.x + ((Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA - _pieza->getAncho()) / 2);
	int y = _puntoInicial.y + ((Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA - _pieza->getAlto()) / 2);

	_pieza->setX(x);
	_pieza->setY(y);
}

Ajedrez::Pieza* Ajedrez::Casillero::getPieza()
{
	return _pieza;
}

void Ajedrez::Casillero::calcularCoordenadas()
{
	_puntoInicial.x = _puntoInicialTablero.x + (Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA * _coordenada.columna);
	_puntoInicial.y = _puntoInicialTablero.y + (Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA * _coordenada.fila);
	_puntoFinal.x = _puntoInicial.x + Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA;
	_puntoFinal.y = _puntoInicial.y + Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA;
}

bool Ajedrez::Casillero::puntoEnArea(Ajedrez::coordPantalla punto)
{
	return punto.x >= _puntoInicial.x && punto.y >= _puntoInicial.y && punto.x <= _puntoFinal.x && punto.x <= _puntoFinal.y;
}

void Ajedrez::Casillero::dibujar()
{
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
	rectangle(_puntoInicial.x, _puntoInicial.y, _puntoFinal.x, _puntoFinal.y);

	if (_pieza != NULL)
		_pieza->dibujar();
}