#include "Ajedrez.h"

Ajedrez::Torre::Torre():Ajedrez::Pieza()
{
	setAncho((Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
	setAlto((Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
}

Ajedrez::Torre::~Torre()
{}

bool Ajedrez::Torre::getPuedeSaltar()
{
	return false;
}

int Ajedrez::Torre::getTipoPieza()
{
	return Ajedrez::Pieza::TORRE;
}

char* Ajedrez::Torre::getIcono()
{
	char* rutaIcono = new char[30];

	Juego::Equipo* equipo = getEquipo();

	sprintf(rutaIcono, "img\\piezas\\torre_%c.gif", ((Ajedrez::Equipo*)equipo)->getColor());
	
	return rutaIcono;
}

void Ajedrez::Torre::mover()
{}

bool Ajedrez::Torre::movimientoValido()
{
	return false;
}

Ajedrez::coordTablero Ajedrez::Torre::getCoordenadaInicial()
{
	Ajedrez::coordTablero coordenada;

	Juego::Equipo* equipo = getEquipo();

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_NEGRO)
		coordenada.fila = 0;

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_BLANCO)
		coordenada.fila = 7;

	coordenada.columna = 0;

	return coordenada;
}

void Ajedrez::Torre::dibujar()
{
	setRutaImagen(getIcono(), getAncho(), getAlto());

	Grafica::Imagen::dibujar();
}