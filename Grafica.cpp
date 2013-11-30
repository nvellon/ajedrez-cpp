#include "Grafica.h"

/**
 * Dibujable
 */
Grafica::Dibujable::Dibujable()
{
	_x = 0;
	_y = 0;
};

void Grafica::Dibujable::setX(int x)
{
	_x = x;
};

int Grafica::Dibujable::getX()
{
	return _x;
};

void Grafica::Dibujable::setY(int y)
{
	_y = y;
};

int Grafica::Dibujable::getY()
{
	return _y;
};

/**
 * Composicion
 */
Grafica::Composicion::Composicion()
{
	// Nada que hacer
};

Grafica::Composicion::~Composicion()
{
	vaciar();
};

void Grafica::Composicion::agregar(Grafica::Dibujable* componente)
{
	_componente.push_back(componente);
};

void Grafica::Composicion::vaciar()
{
	for (int i = 0; i < _componente.size(); i++)
		delete _componente[i];

	_componente.erase(_componente.begin(), _componente.end());
};

void Grafica::Composicion::dibujar()
{
	for (int i = 0; i < _componente.size(); i++)
		_componente[i]->dibujar();
};

/**
 * Pantalla
 */
Grafica::Pantalla::Pantalla(char* titulo, int ancho, int alto):Grafica::Composicion()
{
	_titulo = titulo;
	_ancho = ancho;
	_alto = alto;
}

void Grafica::Pantalla::dibujar()
{
	initwindow(_ancho, _alto, _titulo);

	Grafica::Composicion::dibujar();
}

/**
 * texto
 */
void Grafica::Texto::dibujar()
{
	// Dibujar texto
};

/**
 * Imagen
 */
Grafica::Imagen::Imagen(char* rutaImagen, int ancho, int alto):Grafica::Dibujable()
{
	setRutaImagen(rutaImagen, ancho, alto);
};

void Grafica::Imagen::setRutaImagen(char* rutaImagen, int ancho, int alto)
{
	_ancho = ancho;
	_alto = alto;
	_rutaImagen = rutaImagen;
};

char* Grafica::Imagen::getRutaImagen()
{
	return _rutaImagen;
};

void Grafica::Imagen::dibujar()
{
	readimagefile(_rutaImagen, getX(), getY(), getX() + _ancho, getY() + _alto);
};

/**
 * Forma
 */
void Grafica::Forma::dibujar()
{
	// Dibujar forma
};