#include "Juego.h"

void Juego::Ciclo::comenzar()
{
	setup();

	while (!finalizo())
	{
		ingresoJugador();

		actualizarJuego();

		actualizarPantalla();
	}

	apagado();
}