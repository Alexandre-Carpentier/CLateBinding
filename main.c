#include "main.h"

#define MAX_POOL 64
#define CREATE_DEVICE(type, ptr, addr) 		ptr = malloc(sizeof(OSCOPE));if (ptr == NULL) { return FALSE; }oscope_constructor((OSCOPE*)&(*ptr), addr)

BOOL BuildObjectPool(DEVICE* DevicePool[])
{
	// Without macro
	OSCOPE* pOscope0 = malloc(sizeof(OSCOPE));
	if (pOscope0 == NULL) { return FALSE; }
	oscope_constructor((OSCOPE*)&(*pOscope0), "COM0");

	DevicePool[0] = (DEVICE*)pOscope0;

	MULTIMETRE* pMultimetre1 = malloc(sizeof(MULTIMETRE));
	if (pMultimetre1 == NULL)
		return FALSE;
	DevicePool[1] = (DEVICE*)pMultimetre1;
	multimetre_constructor((MULTIMETRE*)&(*DevicePool[1]), "COM1", 0);

	MULTIMETRE* pMultimetre2 = malloc(sizeof(MULTIMETRE));
	if (pMultimetre2 == NULL)
		return FALSE;
	DevicePool[2] = (DEVICE*)pMultimetre2;
	multimetre_constructor((MULTIMETRE*)&(*DevicePool[2]), "COM2", 1);

	// With macro
	OSCOPE* pOscope1 = NULL;
	CREATE_DEVICE(OSCOPE, pOscope1, "COM3");
	if (pOscope1 != NULL)
	{
		DevicePool[3] = (DEVICE*)pOscope1;
	}

	OSCOPE* pOscope2 = NULL;
	CREATE_DEVICE(OSCOPE, pOscope2, "COM4");
	if (pOscope2 != NULL)
	{
		DevicePool[4] = (DEVICE*)pOscope2;
	}

	return TRUE;
}

void DestroyObjectPool(DEVICE* DevicePool[], int nItem)
{
	for (int i = 0; i < nItem; i++)
	{
		if (*(DevicePool) == NULL)
			return;
		free(*(DevicePool));
		DevicePool++;
	}
}

int main(void)
{
	// Bundle some objects together
	DEVICE* DevicePool[MAX_POOL];
	ZeroMemory(DevicePool, sizeof(DevicePool));
	int iObjectNumbers = 0;
	if (!BuildObjectPool(&DevicePool))
	{
		return EXIT_FAILURE;
	}

	// Use the array of object with virtual method read_value()
	int i = 0;
	do
	{
		printf("Device return : %lf\n", read_value((DEVICE* const)&(*DevicePool[i])));
		i++;
	} while (DevicePool[i] != NULL);

	// Free objects
	DestroyObjectPool(DevicePool, MAX_POOL);
	return EXIT_SUCCESS;
}


