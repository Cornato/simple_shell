#include "main.h"

/**
 * setEnvironmentVariable - Sets or updates an environment variable.
 * @variable: Name of the environment variable.
 * @value: Value to set for the environment variable.
 */
void setEnvironmentVariable(char *variable, char *value)
{
	if (setenv(variable, value, 1) == -1)
		perror("setenv");
}

/**
 * unsetEnvironmentVariable - Unsets an environment variable.
 * @variable: Name of the environment variable to unset.
 * @env: Pointer to the array of environment variables.
 */
void unsetEnvironmentVariable(char *variable, char ***env)
{
	if (unsetenv(variable) == -1)
		perror("unsetenv");
	else
		*env = __environ;
}

/**
 * EnviromentLog - Displays the current environment variables.
 * @envc: Pointer to the array of environment variables.
 */
void EnviromentLog(char **envc)
{
	for (; *envc; envc++)
	{
		write(STDOUT_FILENO, *envc, strlen(*envc));
		write(STDOUT_FILENO, "\n", 1);
	}
}
