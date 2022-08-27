#include "multimetre.h"
BOOL multimetre_constructor(MULTIMETRE* const _this, char* address, int mode)
{
	// initialisation de la vtable multimetre puis remplace le pointeur initial
	static struct Virtual_T vtab = {
		&multimetre_read_value
	};

	// initialise la vtable de device
	device_constructor(&_this->device, address);

	// remplace la valeure pointee de device par multimetre
	_this->device.pvirtual = &vtab;

	_this->mode = mode;
	return TRUE;
}

static double multimetre_read_value(MULTIMETRE* const _this)
{
	if (_this->mode == 0)
		return 60.0;
	if (_this->mode == 1)
		return 120.0;

	return -1.0;
}