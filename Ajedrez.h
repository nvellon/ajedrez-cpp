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
protected:
	void crearGrilla();
	void dibujarRotulos();

public:
	static const int CELDAS_POR_LADO = 8;
	static const int SEPARACION_TABLERO_ROTULO_ANCHO = 15;
	static const int SEPARACION_TABLERO_ROTULO_ALTO = 20;
	static const int GRILLA_IMAGEN_ANCHO = 500;
	static const int GRILLA_IMAGEN_ALTO = 500;
	static const int GRILLA_IMAGEN_ANCHO_CELDA = 62;
	static const int GRILLA_IMAGEN_ALTO_CELDA = 62;

	int _x;
	int _y;
	Grafica::Imagen* _grilla;

	Tablero(int x, int y);
	~Tablero();
	int getX();
	void setX(int x); 
	int getY();
	void setY(int y);
	void dibujar();
};