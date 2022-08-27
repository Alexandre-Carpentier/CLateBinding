#ifndef _OSCOPE_H_
#define _OSCOPE_H_
#include <Windows.h>
#include "baseclass.h"
// Class dérivée pour un osciloscope
typedef struct {
	DEVICE device;
	int freq;
}OSCOPE, * POSCOPE;
BOOL oscope_constructor(OSCOPE* const _this, char* address);
static double oscope_read_value(OSCOPE* const _this);
#endif