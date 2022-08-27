#include "main.h"

void *BuildObjectPool(int *iObjectNumbers, DEVICE* DevicePool[64])
{
	
	POSCOPE pOscope = malloc(sizeof(OSCOPE));
	if (pOscope == NULL)
		return NULL;
	DevicePool[0] = (DEVICE *)pOscope;
	oscope_constructor((OSCOPE*)&(*DevicePool[0]), "COM0");

	PMULTIMETRE pMultimetre1 = malloc(sizeof(MULTIMETRE));
	if (pMultimetre1 == NULL)
		return NULL;
	DevicePool[1] = (DEVICE*)pMultimetre1;	
	multimetre_constructor((MULTIMETRE*) & (*DevicePool[1]), "COM1", 0);

	PMULTIMETRE pMultimetre2 = malloc(sizeof(MULTIMETRE));
	if (pMultimetre2 == NULL)
		return NULL;
	DevicePool[2] = (DEVICE*)pMultimetre2;
	multimetre_constructor((MULTIMETRE*)&(*DevicePool[2]), "COM2", 1);

	*iObjectNumbers = 3;
	return NULL;
}

int main(void)
{
	// Bundle some objects together
	DEVICE* DevicePool[64];
	int iObjectNumbers = 0;
	BuildObjectPool(&iObjectNumbers, &DevicePool);

	// Use the array of object with virtual method read_value()
	for (int i = 0; i < iObjectNumbers; i++)
	{
		printf("Device return : %lf\n", read_value((DEVICE* const)&(*DevicePool[i])));
	}
	return EXIT_SUCCESS;
}


