#include "Grafica.h"

/**
 * Dibujable
 */
Grafica::Dibujable::Dibujable()
{
	_x = 0;
	_y = 0;
};

Grafica::Dibujable::~Dibujable()
{
	//
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
Grafica::Composicion::Composicion():Grafica::Dibujable()
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

void Grafica::Pantalla::mostrarPosMouse(bool mostrar) 
{
	if (mostrar) {
		char buffer[20] = "";

		setcolor(15);
		settextstyle(0, 0, 0);
		outtextxy(0,  0, "X =       ");
		outtextxy(0, 14, "Y =       ");
		itoa(mousex(), buffer, 10); // mousex() nos devuelve la posicion x actual del mouse.
		outtextxy(35, 0, buffer);
		itoa(mousey(), buffer, 10); // mousey() nos devuelve la posicion y actual del mouse.
		outtextxy(35, 14, buffer);
	}
}

void Grafica::Pantalla::dibujar()
{
	initwindow(_ancho, _alto, _titulo);

	Grafica::Composicion::dibujar();
}

/**
 * texto
 */
Grafica::Texto::Texto(char* texto):Grafica::Dibujable()
{
	_texto = texto;
};

Grafica::Texto::~Texto()
{
	delete[] _texto;
}

void Grafica::Texto::dibujar()
{
	outtextxy(getX(), getY(), _texto);
};

/**
 * Imagen
 */
Grafica::Imagen::Imagen():Grafica::Dibujable()
{
	setRutaImagen("", 0, 0);
};

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

void Grafica::Imagen::setAncho(int ancho)
{
	_ancho = ancho;
}

void Grafica::Imagen::setAlto(int alto)
{
	_alto = alto;
}

void Grafica::Imagen::dibujar()
{
	readimagefile(_rutaImagen, getX(), getY(), getX() + _ancho, getY() + _alto);
};

/**
 * Linea
 */
Grafica::Linea::Linea(int x1, int y1, int x2, int y2)
{
	setX(x1);
	setY(y1);
	_x2 = x2;
	_y2 = y2;
};

void Grafica::Linea::dibujar()
{
	line(getX(), getY(), _x2, _y2);
};

/**
 * Rectangulo
 */
Grafica::Rectangulo::Rectangulo(int x1, int y1, int x2, int y2)
{
	setX(x1);
	setY(y1);
	_x2 = x2;
	_y2 = y2;

	_anchoLinea = NULL;
	_colorRelleno = NULL;
	_tipoRelleno = NULL;
	_3d = false;
}

void Grafica::Rectangulo::setTipoRelleno(int tipo)
{
	_tipoRelleno = tipo;
}

void Grafica::Rectangulo::setColorRelleno(int color)
{
	_colorRelleno = color;
}

void Grafica::Rectangulo::setAnchoLinea(int pixels)
{
	_anchoLinea = pixels;
}

void Grafica::Rectangulo::set3d(bool enabled)
{
	_3d = enabled;
}

void Grafica::Rectangulo::dibujar()
{
	if (_anchoLinea != NULL)
		setlinestyle(SOLID_LINE, 0, _anchoLinea);

	if (_colorRelleno != NULL && _tipoRelleno != NULL)
		setfillstyle(_tipoRelleno, _colorRelleno);

	if (_3d)
	{
		bar3d(getX(), getY(), _x2, _y2, 10, 0);
	}
	else
	{
		bar(getX(), getY(), _x2, _y2);
	}
}