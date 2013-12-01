#include "Ajedrez.h"

Ajedrez::Ciclo::Ciclo()
{
	_finalizo = false;
	_pantalla = new Grafica::Pantalla("Ajedrez - Grupo 6", 800, 600);
	
	_tablero = new Ajedrez::Tablero(30, 20);
	_pantalla->agregar(_tablero);

	_menu = new Ajedrez::Menu(580, 0);
	_pantalla->agregar(_menu);

	_equipoNegro = new Ajedrez::Equipo("Negras");
	_equipoNegro->setColor(Ajedrez::EQUIPO_NEGRO);

	int x = 50;

	for (int i = 0; i < Ajedrez::CANTIDAD_PEON; i++)
	{
		_pieza[i] = new Ajedrez::Peon();
		_pieza[i]->setEquipo(_equipoNegro);
		_pieza[i]->setX(x);
		_pieza[i]->setY(110);

		x += Ajedrez::Tablero::GRILLA_IMAGEN_ANCHO_CELDA;

		_pantalla->agregar(_pieza[i]);
	}

	_equipoBlanco = new Ajedrez::Equipo("Blancas");
	_equipoBlanco->setColor(Ajedrez::EQUIPO_BLANCO);
}

Ajedrez::Ciclo::~Ciclo()
{
	delete _pantalla;
	delete _tablero;
	delete _menu;
}

void Ajedrez::Ciclo::setup()
{
	cout << "Setup" << endl;
}

void Ajedrez::Ciclo::ingresoJugador()
{
	_finalizo = true;

	cout << "Ingreso Jugador" << endl;
}

void Ajedrez::Ciclo::actualizarJuego()
{
	cout << "Actualizar Juego" << endl;
}

void Ajedrez::Ciclo::actualizarPantalla()
{
	_pantalla->dibujar();
	cout << "Actualizar Pantalla" << endl;
}

bool Ajedrez::Ciclo::finalizo()
{
	cout << "Finalizo" << endl;
	return _finalizo;
}

void Ajedrez::Ciclo::apagado()
{
	cout << "Apagado" << endl;
	
	while (!kbhit())
	{
		delay(100);

		_pantalla->mostrarPosMouse(true);
	}
}