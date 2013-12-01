#include "Ajedrez.h"

Ajedrez::Ciclo::Ciclo()
{
	_finalizo = false;

	_pantalla = new Grafica::Pantalla("Ajedrez - Grupo 6", 800, 600);

	_menu = new Ajedrez::Menu(580, 0);
	_pantalla->agregar(_menu);
	
	_tablero = new Ajedrez::Tablero(30, 40);

	// Negras
	_equipoNegro = new Ajedrez::Equipo("Negras");
	inicarEquipo(_equipoNegro, Ajedrez::EQUIPO_NEGRO);

	// Blancas
	_equipoBlanco = new Ajedrez::Equipo("Blancas");
	inicarEquipo(_equipoBlanco, Ajedrez::EQUIPO_BLANCO);

	_pantalla->agregar(_tablero);
}

Ajedrez::Ciclo::~Ciclo()
{
	delete _pantalla;
	delete _tablero;
	delete _menu;
}

void Ajedrez::Ciclo::inicarEquipo(Ajedrez::Equipo* equipo, char color)
{
	equipo->setColor(color);

	int posIni = 0;
	if (color == Ajedrez::EQUIPO_BLANCO)
		posIni += Ajedrez::CANTIDAD_PIEZAS_EQUIPO;

	int posIniPeon = posIni + Ajedrez::CANTIDAD_PEON;

	int i = posIni;
	while (i < posIniPeon)
	{
		_pieza[i] = new Ajedrez::Peon();
		_pieza[i]->setEquipo(equipo);

		_tablero->agregarPieza(_pieza[i]);

		i++;
	}
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