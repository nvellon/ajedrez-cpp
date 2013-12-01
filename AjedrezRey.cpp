#include "Ajedrez.h"

Ajedrez::Rey::Rey():Ajedrez::Pieza()
{
	setAncho((Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
	setAlto((Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
}

Ajedrez::Rey::~Rey()
{}

bool Ajedrez::Rey::getPuedeSaltar()
{
	return false;
}

int Ajedrez::Rey::getTipoPieza()
{
	return Ajedrez::Pieza::REY;
}

char* Ajedrez::Rey::getIcono()
{
	char* rutaIcono = new char[30];

	Juego::Equipo* equipo = getEquipo();

	sprintf(rutaIcono, "img\\piezas\\rey_%c.gif", ((Ajedrez::Equipo*)equipo)->getColor());
	
	return rutaIcono;
}

void Ajedrez::Rey::mover()
{}

bool Ajedrez::Rey::movimientoValido()
{
	return false;
}

Ajedrez::coordTablero Ajedrez::Rey::getCoordenadaInicial()
{
	Ajedrez::coordTablero coordenada;

	Juego::Equipo* equipo = getEquipo();

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_NEGRO)
		coordenada.fila = 0;

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_BLANCO)
		coordenada.fila = 7;

	cout << coordenada.fila << endl;
	coordenada.columna = 4;

	return coordenada;
}

void Ajedrez::Rey::dibujar()
{
	setRutaImagen(getIcono(), getAncho(), getAlto());

	Grafica::Imagen::dibujar();
}