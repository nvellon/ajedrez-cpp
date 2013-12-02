#include "Ajedrez.h"

Ajedrez::Ciclo::Ciclo()
{
	_finalizo = false;

	_manejadorClick = new Grafica::ManejadorClick();

	// Creo pantalla
	_pantalla = new Grafica::Pantalla("Ajedrez - Grupo 6", 800, 600);

	// Creo menu
	_menu = new Ajedrez::Menu(580, 0);

	// Creo tablero
	_tablero = new Ajedrez::Tablero(30, 40);

	// Equipo Negro
	_equipoNegro = new Ajedrez::Equipo("Negras");

	// Equipo Blanco
	_equipoBlanco = new Ajedrez::Equipo("Blancas");
}

Ajedrez::Ciclo::~Ciclo()
{
	delete _pantalla;
	delete _tablero;
	delete _menu;
	delete _manejadorClick;
}

void Ajedrez::Ciclo::inicarEquipo(Ajedrez::Equipo* equipo, char color)
{
	equipo->setColor(color);

	int posIni = 0;
	if (color == Ajedrez::EQUIPO_BLANCO)
		posIni += Ajedrez::CANTIDAD_PIEZAS_EQUIPO;

	// Peones
	int posFinPeon = posIni + Ajedrez::CANTIDAD_PEON;

	int i = posIni;
	while (i < posFinPeon)
	{
		_pieza[i] = new Ajedrez::Peon();
		_pieza[i]->setEquipo(equipo);

		_tablero->agregarPieza(_pieza[i]);

		i++;
	}

	// Torres
	int posFinTorre = posFinPeon + Ajedrez::CANTIDAD_TORRE;

	while (i < posFinTorre)
	{
		_pieza[i] = new Ajedrez::Torre();
		_pieza[i]->setEquipo(equipo);

		_tablero->agregarPieza(_pieza[i]);

		i++;
	}

	// Caballos
	int posFinCaballo = posFinTorre + Ajedrez::CANTIDAD_CABALLO;

	while (i < posFinCaballo)
	{
		_pieza[i] = new Ajedrez::Caballo();
		_pieza[i]->setEquipo(equipo);

		_tablero->agregarPieza(_pieza[i]);

		i++;
	}

	// Alfiles
	int posFinAlfil = posFinCaballo + Ajedrez::CANTIDAD_ALFIL;

	while (i < posFinAlfil)
	{
		_pieza[i] = new Ajedrez::Alfil();
		_pieza[i]->setEquipo(equipo);

		_tablero->agregarPieza(_pieza[i]);

		i++;
	}

	// Reina
	_pieza[i] = new Ajedrez::Reina();
	_pieza[i]->setEquipo(equipo);

	_tablero->agregarPieza(_pieza[i]);

	i++;

	// Rey
	_pieza[i] = new Ajedrez::Rey();
	_pieza[i]->setEquipo(equipo);

	_tablero->agregarPieza(_pieza[i]);

	i++;
}

void Ajedrez::Ciclo::setup()
{
	inicarEquipo(_equipoNegro, Ajedrez::EQUIPO_NEGRO);
	inicarEquipo(_equipoBlanco, Ajedrez::EQUIPO_BLANCO);

	_pantalla->agregar(_menu);
	_pantalla->agregar(_tablero);

	_manejadorClick->agregarObservador(_menu);
	_manejadorClick->agregarObservador(_tablero);

	_pantalla->dibujar();
}

void Ajedrez::Ciclo::ingresoJugador()
{
	while (!_manejadorClick->escuchar())
	{
		_pantalla->mostrarPosMouse(true);

		delay(100);
	}
}

void Ajedrez::Ciclo::actualizarJuego()
{
	Ajedrez::Casillero* casilleroAnt = _tablero->getCasilleroAnterior();
	Ajedrez::Casillero* casilleroSel = _tablero->getCasilleroActual();

	if (casilleroAnt->getPieza() != NULL)
	{
		casilleroSel->setPieza(casilleroAnt->getPieza());
		casilleroAnt->setPieza(NULL);
	}
}

void Ajedrez::Ciclo::actualizarPantalla()
{
	//_pantalla->dibujar();
}

bool Ajedrez::Ciclo::finalizo()
{
	return _finalizo;
}

void Ajedrez::Ciclo::apagado()
{
}