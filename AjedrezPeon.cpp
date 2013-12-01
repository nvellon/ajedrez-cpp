#include "Ajedrez.h"

Ajedrez::Peon::Peon():Ajedrez::Pieza()
{
	setAncho((Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
	setAlto((Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
}

Ajedrez::Peon::~Peon()
{}

bool Ajedrez::Peon::getPuedeSaltar()
{
	return false;
}

int Ajedrez::Peon::getTipoPieza()
{
	return Ajedrez::Pieza::PEON;
}

char* Ajedrez::Peon::getIcono()
{
	char* rutaIcono = new char[30];

	Juego::Equipo* equipo = getEquipo();

	sprintf(rutaIcono, "img\\piezas\\peon_%c.gif", ((Ajedrez::Equipo*)equipo)->getColor());
	
	return rutaIcono;
}

void Ajedrez::Peon::mover()
{}

bool Ajedrez::Peon::movimientoValido()
{
	return false;
}

Ajedrez::coordTablero Ajedrez::Peon::getCoordenadaInicial()
{
	Ajedrez::coordTablero coordenada;

	Juego::Equipo* equipo = getEquipo();

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_NEGRO)
		coordenada.fila = 1;

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_BLANCO)
		coordenada.fila = 6;

	cout << coordenada.fila << endl;
	coordenada.columna = 0;

	return coordenada;
}

void Ajedrez::Peon::dibujar()
{
	setRutaImagen(getIcono(), getAncho(), getAlto());

	Grafica::Imagen::dibujar();
}