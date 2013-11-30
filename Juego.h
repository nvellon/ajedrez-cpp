#include <iostream>
#include "Grafica.h"

using namespace std;

namespace Juego
{
	class Ciclo;
	class Jugador;
	class Equipo;
	class Pieza;
};


class Juego::Ciclo
{
protected:
	virtual void setup()=0;
	virtual void ingresoJugador()=0;
	virtual void actualizarJuego()=0;
	virtual void actualizarPantalla()=0;
	virtual bool finalizo()=0;
	virtual void apagado()=0;
public:
	void comenzar();
};


class Juego::Pieza
{
protected:
	char _color;
	char _icono;
	bool _puedeSaltar;
public:
	Pieza();
	virtual ~Pieza();
	void setIcono(char icono);
	char getIcono();
	virtual char getTipoPieza()=0;
	virtual void mover()=0;
	virtual bool movimientoValido()=0;
};