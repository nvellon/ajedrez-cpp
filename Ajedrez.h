#include <iostream>
#include "Juego.h"

using namespace std;

namespace Ajedrez
{
	const int CANTIDAD_PIEZAS_EQUIPO = 16;
	const int CANTIDAD_REY = 1;
	const int CANTIDAD_REINA = 1;
	const int CANTIDAD_PEON = 8;
	const int CANTIDAD_TORRE = 2;
	const int CANTIDAD_CABALLO = 2;
	const int CANTIDAD_ALFIL = 2;

	const char EQUIPO_NEGRO = 'n';
	const char EQUIPO_BLANCO = 'b';

	class Ciclo;
	class Tablero;
	class Casillero;
	class Menu;
	class Equipo;
	class Pieza;
	class Peon;
	class Torre;
	class Caballo;
	class Alfil;
	class Reina;
	class Rey;
};

/**
 * Ajedrez::Ciclo
 */
class Ajedrez::Ciclo:public Juego::Ciclo
{
protected:
	bool _finalizo;
	Grafica::Pantalla* _pantalla;
	Ajedrez::Tablero* _tablero;
	Ajedrez::Menu* _menu;
	Ajedrez::Equipo* _equipoNegro;
	Ajedrez::Equipo* _equipoBlanco;
	Ajedrez::Pieza* _pieza[Ajedrez::CANTIDAD_PIEZAS_EQUIPO * 2];

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
	static const int PORCENTAJE_TAMANO_PIEZA_CELDA = 80;

	Grafica::Imagen* _grilla;

	Tablero(int x, int y);
	~Tablero();
	void dibujar();
};

/**
 * Ajedrez::Menu
 */
class Ajedrez::Menu:public Grafica::Composicion
{
protected:
	static const int ANCHO = 200;
	static const int ALTO = 599;

	Grafica::Rectangulo* _fondo;

	void crearFondo();

public:
	Menu(int x, int y);
	~Menu();
	//void dibujar();
};

/**
 * Ajedrez::Equipo
 */
class Ajedrez::Equipo:public Juego::Equipo
{
protected:
	char _color;

public:
	Equipo(char* nombre);
	~Equipo();
	void setColor(char color);
	char getColor();
};

/**
 * Ajedrez::Pieza
 */
class Ajedrez::Pieza:public Juego::Pieza
{
protected:
	bool _puedeSaltar;

public:
	Pieza();
	~Pieza();
	virtual bool getPuedeSaltar()=0;
};

/**
 * Ajedrez::Peon
 */
class Ajedrez::Peon:public Ajedrez::Pieza
{
protected:
	//

public:
	Peon();
	~Peon();
	char* getIcono();
	bool getPuedeSaltar();
	char getTipoPieza();
	void mover();
	bool movimientoValido();
	void dibujar();
};