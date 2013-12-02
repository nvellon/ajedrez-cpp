#include "Ajedrez.h"

Ajedrez::Caballo::Caballo():Ajedrez::Pieza()
{
	setAncho((Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
	setAlto((Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
}

Ajedrez::Caballo::~Caballo()
{}

bool Ajedrez::Caballo::getPuedeSaltar()
{
	return false;
}

int Ajedrez::Caballo::getTipoPieza()
{
	return Ajedrez::Pieza::CABALLO;
}

char* Ajedrez::Caballo::getIcono()
{
	char* rutaIcono = new char[30];

	Juego::Equipo* equipo = getEquipo();

	sprintf(rutaIcono, "img\\piezas\\caballo_%c.gif", ((Ajedrez::Equipo*)equipo)->getColor());
	
	return rutaIcono;
}

void Ajedrez::Caballo::mover()
{}

bool Ajedrez::Caballo::movimientoValido()
{
	return false;
}

Ajedrez::coordTablero Ajedrez::Caballo::getCoordenadaInicial()
{
	Ajedrez::coordTablero coordenada;

	Juego::Equipo* equipo = getEquipo();

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_NEGRO)
		coordenada.fila = 0;

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_BLANCO)
		coordenada.fila = 7;

	coordenada.columna = 1;

	return coordenada;
}

void Ajedrez::Caballo::dibujar()
{
	setRutaImagen(getIcono(), getAncho(), getAlto());

	Grafica::Imagen::dibujar();
}