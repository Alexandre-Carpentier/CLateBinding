#ifndef _BASECLASS_H_
#define _BASECLASS_H_
#include <Windows.h>

// Base class
typedef struct {
	struct Virtual_T* pvirtual;
	char szAddress[MAX_PATH];
}DEVICE, * PDEVICE;

// Virtual table
struct Virtual_T {
	double (*read_value) (DEVICE* const _this);
};

static double read_value(DEVICE* const _this)
{
	return (*_this->pvirtual->read_value)(_this);
}

void device_constructor(DEVICE* const _this, char* address);
static double read_value(DEVICE* const _this);

#endif