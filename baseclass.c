#include "baseclass.h"
void device_constructor(DEVICE* const _this, char* address)
{
	// Initialisation de la table de fonction virtuelle
	static struct Virtual_T vtable = { &read_value };
	// Initialisation du pointeur de la table
	_this->pvirtual = &vtable;

	strcpy_s(_this->szAddress, MAX_PATH, address);
}

