#include "Ajedrez.h"

Ajedrez::Ciclo::Ciclo()
{
	_finalizo = false;
	_pantalla = new Grafica::Pantalla("Ajedrez - Grupo 6", 800, 600);
	
	Ajedrez::Tablero* tablero = new Ajedrez::Tablero(50, 40);
	_pantalla->agregar(tablero);
}

Ajedrez::Ciclo::~Ciclo()
{
	delete _pantalla;
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
	cin.get();
}