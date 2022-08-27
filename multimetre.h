#ifndef _MULTIMETER_H_
#define _MULTIMETER_H_
#include <Windows.h>
#include "baseclass.h"
// Class dérivée pour un multimetre
typedef struct {
	DEVICE device;
	int mode;
}MULTIMETRE, * PMULTIMETRE;
BOOL multimetre_constructor(MULTIMETRE* const _this, char* address, int mode);
static double multimetre_read_value(MULTIMETRE* const _this);
#endif
