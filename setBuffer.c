#include "main.h"
/**
 * clearBuffer - Clears the buffer by setting all elements to NULL.
 * @buffer: Array to be cleared.
 * @size: Size of the array.
 */
void clearBuffer(char *buffer[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		buffer[i] = NULL;
}
