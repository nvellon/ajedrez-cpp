#include <iostream>
#include <vector>
#include "../../bgi/graphics.h"

using namespace std;


/**
 * Grafica Namespace
 */
namespace Grafica
{
	class ManejadorClick;
	class Clickable;
	class Dibujable;
	class Composicion;
	class Pantalla;
	class Imagen;
	class Texto;
	class Linea;
	class Rectangulo;
};


/**
 * ManejadorClick
 */
class Grafica::ManejadorClick
{
protected:
	vector<Grafica::Clickable*> _observador;

public:
	ManejadorClick();
	~ManejadorClick();
	void agregarObservador(Grafica::Clickable* observador);
	bool escuchar();
	void notificar(int x, int y, int tipo);
};


/**
 * Clickable
 */
class Grafica::Clickable
{
public:
	Clickable();
	~Clickable();
	virtual void notificar(int x, int y, int tipo)=0;
};


/**
 * Dibujable
 */
class Grafica::Dibujable:public Grafica::Clickable
{
private:
	int _x;
	int _y;

public:
	Dibujable();
	~Dibujable();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	virtual void dibujar()=0;
};


/**
 * Composicion
 */
class Grafica::Composicion:public Grafica::Dibujable
{
protected:
	vector<Grafica::Dibujable*> _componente;

public:
	Composicion();
	~Composicion();
	void agregar(Grafica::Dibujable* componente);
	void vaciar();
	void notificar(int x, int y, int tipo);
	void dibujar();
};


/**
 * Pantalla
 */
class Grafica::Pantalla:public Grafica::Composicion
{
private:
	char* _titulo;
	int _ancho;
	int _alto;

public:
	Pantalla(char* titulo, int ancho, int alto);
	void mostrarPosMouse(bool mostrar);
	void notificar(int x, int y, int tipo);
	void dibujar();
};

/**
 * Texto
 */
class Grafica::Texto:public Grafica::Dibujable
{
protected:
	char* _texto;

public:
	Texto(char* texto);
	~Texto();
	void notificar(int x, int y, int tipo);
	void dibujar();
};

/**
 * Imagen
 */
class Grafica::Imagen:public Grafica::Dibujable
{
private:
	char* _rutaImagen;
	int _ancho;
	int _alto;

public:
	Imagen();
	Imagen(char* rutaImagen, int ancho, int alto);
	void setRutaImagen(char* rutaImagen, int ancho, int alto);
	char* getRutaImagen();
	void setAncho(int ancho);
	int getAncho();
	void setAlto(int alto);
	int getAlto();
	void notificar(int x, int y, int tipo);
	void dibujar();
};

/**
 * Linea
 */
class Grafica::Linea:public Grafica::Dibujable
{
private: 
	int _x2;
	int _y2;

public:
	Linea(int x1, int y1, int x2, int y2);
	void notificar(int x, int y, int tipo);
	void dibujar();
};

/**
 * Rectangulo
 */
class Grafica::Rectangulo:public Grafica::Dibujable
{
private: 
	int _x2;
	int _y2;
	int _tipoRelleno;
	int _colorRelleno;
	int _anchoLinea;
	int _3d;

public:
	Rectangulo(int x1, int y1, int x2, int y2);
	void setTipoRelleno(int tipo);
	void setColorRelleno(int color);
	void setAnchoLinea(int pixels);
	void set3d(bool enabled);
	void notificar(int x, int y, int tipo);
	void dibujar();
};