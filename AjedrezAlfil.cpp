#include "Ajedrez.h"

Ajedrez::Alfil::Alfil():Ajedrez::Pieza()
{
	setAncho((Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
	setAlto((Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA * Ajedrez::Tablero::PORCENTAJE_TAMANO_PIEZA_CELDA) / 100);
}

Ajedrez::Alfil::~Alfil()
{}

bool Ajedrez::Alfil::getPuedeSaltar()
{
	return false;
}

int Ajedrez::Alfil::getTipoPieza()
{
	return Ajedrez::Pieza::ALFIL;
}

char* Ajedrez::Alfil::getIcono()
{
	char* rutaIcono = new char[30];

	Juego::Equipo* equipo = getEquipo();

	sprintf(rutaIcono, "img\\piezas\\alfil_%c.gif", ((Ajedrez::Equipo*)equipo)->getColor());
	
	return rutaIcono;
}

void Ajedrez::Alfil::mover()
{}

bool Ajedrez::Alfil::movimientoValido()
{
	return false;
}

Ajedrez::coordTablero Ajedrez::Alfil::getCoordenadaInicial()
{
	Ajedrez::coordTablero coordenada;

	Juego::Equipo* equipo = getEquipo();

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_NEGRO)
		coordenada.fila = 0;

	if (((Ajedrez::Equipo*)equipo)->getColor() == Ajedrez::EQUIPO_BLANCO)
		coordenada.fila = 7;

	cout << coordenada.fila << endl;
	coordenada.columna = 2;

	return coordenada;
}

void Ajedrez::Alfil::dibujar()
{
	setRutaImagen(getIcono(), getAncho(), getAlto());

	Grafica::Imagen::dibujar();
}