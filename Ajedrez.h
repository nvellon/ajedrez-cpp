#include <iostream>
#include "Juego.h"

using namespace std;

namespace Ajedrez
{
	class Ciclo;
	class Tablero;
};

/**
 * Ajedrez::Ciclo
 */
class Ajedrez::Ciclo:public Juego::Ciclo
{
protected:
	bool _finalizo;
	Grafica::Pantalla* _pantalla;

	void setup();
	void ingresoJugador();
	void actualizarJuego();
	void actualizarPantalla();
	bool finalizo();
	void apagado();

public:
	Ciclo();
	~Ciclo();
};

/**
 * Ajedrez::Tablero
 */
class Ajedrez::Tablero:public Grafica::Composicion
{
public:
	static const int CELDAS_POR_LADO = 8;

	int _x;
	int _y;
	int _anchoCelda;
	int _largoCelda;

	Tablero();
	~Tablero();
	void crearGrilla();
	void crearRotulos();
	int getXInicial(int wWidth);
	int getYInicial(int wHeight);
	int getX();
	void setX(int x); 
	int getY();
	void setY(int y); 
};