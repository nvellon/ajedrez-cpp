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

	typedef struct coordPantalla
	{
		int x;
		int y;
	} coordPantalla;

	typedef struct coordTablero
	{
		int fila;
		int columna;
	} coordTablero;

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

	void inicarEquipo(Ajedrez::Equipo* equipo, char color);

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
	Grafica::Imagen* _grilla;
	Ajedrez::Casillero* _casillero[Ajedrez::CANTIDAD_PIEZAS_EQUIPO][Ajedrez::CANTIDAD_PIEZAS_EQUIPO];

	void crearGrilla();
	void dibujarRotulos();
	void crearCasilleros();

public:
	static const int CELDAS_POR_LADO = 8;
	static const int SEPARACION_TABLERO_ROTULO_ANCHO = 15;
	static const int SEPARACION_TABLERO_ROTULO_ALTO = 20;
	static const int GRILLA_IMAGEN_ANCHO = 480;
	static const int GRILLA_IMAGEN_ALTO = 480;
	static const int GRILLA_IMAGEN_ANCHO_CELDA = 60;
	static const int GRILLA_IMAGEN_ALTO_CELDA = 60;
	static const int PORCENTAJE_TAMANO_PIEZA_CELDA = 80;

	Tablero(int x, int y);
	~Tablero();
	void agregarPieza(Ajedrez::Pieza* pieza);
	void dibujar();
};

/**
 * Ajedrez::Casillero
 */
class Ajedrez::Casillero
{
protected:
	Ajedrez::coordTablero _coordenada;
	Ajedrez::coordPantalla _puntoInicialTablero;
	Ajedrez::Pieza* _pieza;
	Ajedrez::coordPantalla _puntoInicial;
	Ajedrez::coordPantalla _puntoFinal;

public:
	Casillero(Ajedrez::coordTablero coordenada, Ajedrez::coordPantalla puntoInicialTablero);
	~Casillero();
	void setPieza(Ajedrez::Pieza* pieza);
	Ajedrez::Pieza* getPieza();
	void calcularCoordenadas();
	bool puntoEnArea(Ajedrez::coordPantalla punto);
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
	static const int PEON = 0;
	static const int TORRE = 1;
	static const int CABALLO = 2;
	static const int ALFIL = 3;
	static const int REINA = 4;
	static const int REY = 5;

	Pieza();
	~Pieza();
	virtual bool getPuedeSaltar()=0;
	virtual Ajedrez::coordTablero getCoordenadaInicial()=0;
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
	int getTipoPieza();
	void mover();
	bool movimientoValido();
	Ajedrez::coordTablero getCoordenadaInicial();
	void dibujar();
};

/**
 * Ajedrez::Torre
 */
class Ajedrez::Torre:public Ajedrez::Pieza
{
protected:
	//

public:
	Torre();
	~Torre();
	char* getIcono();
	bool getPuedeSaltar();
	int getTipoPieza();
	void mover();
	bool movimientoValido();
	Ajedrez::coordTablero getCoordenadaInicial();
	void dibujar();
};

/**
 * Ajedrez::Caballo
 */
class Ajedrez::Caballo:public Ajedrez::Pieza
{
protected:
	//

public:
	Caballo();
	~Caballo();
	char* getIcono();
	bool getPuedeSaltar();
	int getTipoPieza();
	void mover();
	bool movimientoValido();
	Ajedrez::coordTablero getCoordenadaInicial();
	void dibujar();
};

/**
 * Ajedrez::Alfil
 */
class Ajedrez::Alfil:public Ajedrez::Pieza
{
protected:
	//

public:
	Alfil();
	~Alfil();
	char* getIcono();
	bool getPuedeSaltar();
	int getTipoPieza();
	void mover();
	bool movimientoValido();
	Ajedrez::coordTablero getCoordenadaInicial();
	void dibujar();
};

/**
 * Ajedrez::Reina
 */
class Ajedrez::Reina:public Ajedrez::Pieza
{
protected:
	//

public:
	Reina();
	~Reina();
	char* getIcono();
	bool getPuedeSaltar();
	int getTipoPieza();
	void mover();
	bool movimientoValido();
	Ajedrez::coordTablero getCoordenadaInicial();
	void dibujar();
};

/**
 * Ajedrez::Rey
 */
class Ajedrez::Rey:public Ajedrez::Pieza
{
protected:
	//

public:
	Rey();
	~Rey();
	char* getIcono();
	bool getPuedeSaltar();
	int getTipoPieza();
	void mover();
	bool movimientoValido();
	Ajedrez::coordTablero getCoordenadaInicial();
	void dibujar();
};