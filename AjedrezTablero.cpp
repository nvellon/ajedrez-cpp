#include "Ajedrez.h"

Ajedrez::Tablero::Tablero(int x, int y)
{
	setX(x);
	setY(y);

	crearGrilla();
	crearCasilleros();
}

Ajedrez::Tablero::~Tablero()
{
	delete _grilla;
	delete[] _casillero;
}

void Ajedrez::Tablero::crearGrilla()
{
	_grilla = new Grafica::Imagen("img\\tableros\\tablero_bn.bmp", Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO, Ajedrez::Tablero::GRILLA_IMAGEN_ALTO);
	
	_grilla->setX(getX() + Ajedrez::Tablero::SEPARACION_TABLERO_ROTULO_ANCHO);
	_grilla->setY(getY() + Ajedrez::Tablero::SEPARACION_TABLERO_ROTULO_ALTO);

	agregar(_grilla);
}

void Ajedrez::Tablero::dibujarRotulos()
{
	int _x = getX();
	int _y = getY();

	int x = _x  + Ajedrez::Tablero::SEPARACION_TABLERO_ROTULO_ANCHO + (Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA / 2);
	int y = _y + (Ajedrez::Tablero::SEPARACION_TABLERO_ROTULO_ALTO - 5) + (Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA / 2);

	char* textoX = new char[2];
    textoX[0] = '1';
    textoX[1] = '\0';

    char* textoY = new char[2];
    textoY[0] = 'A';
    textoY[1] = '\0';

	for (int i = 0; i < CELDAS_POR_LADO; i++)
	{
		outtextxy(x, _y, &textoX[0]);
		outtextxy(_x, y, &textoY[0]);

		x += Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA;
		y += Ajedrez::Tablero::GRILLA_IMAGEN_ALTO_CELDA;

		textoX[0]++;
		textoY[0]++;
	}

	delete[] textoX;
	delete[] textoY;
}

void Ajedrez::Tablero::crearCasilleros()
{
	for (int i = 0; i < Ajedrez::Tablero::CELDAS_POR_LADO; i++)
	{
		for (int j = 0; j < Ajedrez::Tablero::CELDAS_POR_LADO; j++)
		{
			Ajedrez::coordTablero coordenada;

			coordenada.fila = i;
			coordenada.columna = j;

			Ajedrez::coordPantalla puntoInicialTablero;

			puntoInicialTablero.x = getX() + Ajedrez::Tablero::SEPARACION_TABLERO_ROTULO_ANCHO;
			puntoInicialTablero.y = getY() + Ajedrez::Tablero::SEPARACION_TABLERO_ROTULO_ALTO;

			_casillero[i][j] = new Ajedrez::Casillero(coordenada, puntoInicialTablero);
		}
	}
}

void Ajedrez::Tablero::agregarPieza(Ajedrez::Pieza* pieza)
{
	Ajedrez::coordTablero coordenada = pieza->getCoordenadaInicial();

	int j = coordenada.columna;

	while (j < Ajedrez::Tablero::CELDAS_POR_LADO && _casillero[coordenada.fila][j]->getPieza() != NULL)
		j++;

	if (j < Ajedrez::Tablero::CELDAS_POR_LADO)
		_casillero[coordenada.fila][j]->setPieza(pieza);
}

void Ajedrez::Tablero::dibujar()
{
	dibujarRotulos();

	Grafica::Composicion::dibujar();

	for (int i = 0; i < Ajedrez::Tablero::CELDAS_POR_LADO; i++)
	{
		for (int j = 0; j < Ajedrez::Tablero::CELDAS_POR_LADO; j++)
		{
			_casillero[i][j]->dibujar();
		}
	}
}