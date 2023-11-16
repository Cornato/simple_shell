#include "main.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: Pointer to the string.
 * Return: The length of the string (excluding the null terminator).
 */
int _strlen(char *s)
{
	int length = strlen(s);

	return (length);
}

/**
 * _strcmp - Compares two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * Return: An integer less than, equal to, or greater than zero
 */
int _strcmp(char *s1, char *s2)
{
	int comparisonResult = strcmp(s1, s2);

	return (comparisonResult);
}

/**
 * _strtok - Tokenizes a string.
 * @__s: The string to be tokenized.
 * @__delim: The delimiter characters.
 * Return: A pointer to the next token or NULL.
 */
char *_strtok(char *__s, const char *__delim)
{
	return (strtok(__s, __delim));
}

/**
 * _strcpy - Copies a string.
 * @dest: The destination buffer to copy the string into.
 * @src: The source string to be copied.
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src)
{
	return (strcpy(dest, src));
}
