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


class Juego::Equipo
{
protected:
	char* _nombre;

public:
	Equipo(char* nombre);
	~Equipo();
};


class Juego::Pieza:public Grafica::Imagen
{
protected:
	char* _icono;
	Juego::Equipo* _equipo;

public:
	Pieza();
	virtual ~Pieza();
	void setEquipo(Juego::Equipo* equipo);
	Juego::Equipo* getEquipo();
	virtual char* getIcono()=0;
	virtual int getTipoPieza()=0;
	virtual void mover()=0;
	virtual bool movimientoValido()=0;
};