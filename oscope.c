#include "oscope.h"
BOOL oscope_constructor(OSCOPE* const _this, char* address)
{
	// initialisation de la vtable multimetre 
	static struct Virtual_T vtab = {
		&oscope_read_value
	};

	// initialise la vtable de device
	device_constructor(&_this->device, address);

	// remplace la valeure pointee de device par oscope
	_this->device.pvirtual = &vtab;

	_this->freq = 1000;
	return TRUE;
}

static double oscope_read_value(OSCOPE* const _this)
{
	return 50.0;
}