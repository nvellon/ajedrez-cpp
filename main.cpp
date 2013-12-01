#include <iostream>
#include "Ajedrez.h"

using namespace std;

void main()
{
	Ajedrez::Ciclo* ajedrez = new Ajedrez::Ciclo();
	
	ajedrez->comenzar();
}