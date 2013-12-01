#include "Ajedrez.h"

Ajedrez::Reina::Reina():Ajedrez::Pieza()
{
	setAncho((Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
	setAlto((Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
}

Ajedrez::Reina::~Reina()
{}

bool Ajedrez::Reina::getPuedeSaltar()
{
	return false;
}

int Ajedrez::Reina::getTipoPieza()
{
	return Ajedrez::Pieza::REINA;
}

char* Ajedrez::Reina::getIcono()
{
	char* rutaIcono = new char[30];

	Juego::Equipo* equipo = getEquipo();

	sprintf(rutaIcono, "img\\piezas\\reina_%c.gif", ((Ajedrez::Equipo*)equipo)->getColor());
	
	return rutaIcono;
}

void Ajedrez::Reina::mover()
{}

bool Ajedrez::Reina::movimientoValido()
{
	return false;
}

Ajedrez::coordTablero Ajedrez::Reina::getCoordenadaInicial()
{
	Ajedrez::coordTablero coordenada;

	Juego::Equipo* equipo = getEquipo();

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_NEGRO)
		coordenada.fila = 0;

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_BLANCO)
		coordenada.fila = 7;

	cout << coordenada.fila << endl;
	coordenada.columna = 3;

	return coordenada;
}

void Ajedrez::Reina::dibujar()
{
	setRutaImagen(getIcono(), getAncho(), getAlto());

	Grafica::Imagen::dibujar();
}