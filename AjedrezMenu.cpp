#include "Ajedrez.h"

Ajedrez::Menu::Menu(int x, int y)
{
	setX(x);
	setY(y);

	crearFondo();
}

Ajedrez::Menu::~Menu()
{
	delete _fondo;
}

void Ajedrez::Menu::crearFondo()
{
	_fondo = new Grafica::Rectangulo(getX(), getY(), 799, 599);
	_fondo->setColorRelleno(CYAN);
	_fondo->setTipoRelleno(CLOSE_DOT_FILL);
	_fondo->setAnchoLinea(3);
	_fondo->set3d(false);

	agregar(_fondo);
}

/*void Ajedrez::Menu::dibujar()
{

}*/