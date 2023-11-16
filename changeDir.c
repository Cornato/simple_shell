#include "main.h"
/**
 * current_directory - Change the current working directory.
 * @current_dir: The target directory or NULL for home directory.
 * Return: 0 on success, -1 on failure.
 */
void current_directory(char *current_dir)
{
	write(STDOUT_FILENO, current_dir, _strlen(current_dir));
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * change_directory - Change the current working directory.
 * @args: argumants.
 * @argv: argv.
 * @previously: previously.
 * @error_c: error_count.
 * Return: 0 on success, -1 on failure.
 */
int change_directory(char *args[], char *argv[], char *previously, int error_c)
{
	char current_dir[100];

	if (_strcmp(args[1], "-") == 0)
	{
		if (previously != NULL)
		{
			if (chdir(previously) != 0)
			{
				return (0);
			}
			else
			{
				if (getcwd(current_dir, sizeof(current_dir)) != NULL)
				{
					current_directory(current_dir);
				}
				return (1);
			}
		}
		else
		{
			if (getcwd(current_dir, sizeof(current_dir)) != NULL)
			{
				current_directory(current_dir);
			}
			return (1);
		}
		return (1);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			fprintf(stderr, "%s: %d: %s: can't cd to %s\n",
				argv[0], error_c, args[0], args[1]);
			return (0);
		}
		return (1);
	}
	return (0);
}

/**
 * cd_cmd_handler - Changes the directory
 * @args: Array of arguments
 * @argv: Program arguments
 * @cmdCount: Number of arguments
 * @error_count: Error count for reporting
 * Return: Exit value
 */
int cd_cmd_handler(char *args[], char *argv[], int cmdCount, int error_count)
{
	char *home = getenv("HOME");
	char *previously = getenv("OLDPWD");
	int value = 0;

	if (_strcmp(args[0], "cd") == 0)
	{
		if (cmdCount > 1)
		{
			value = change_directory(args, argv, previously, error_count);
		}
		else
		{
			if (home != NULL)
			{
				if (chdir(home) != 0)
				{
					value = 0;
					perror("chdir");
				}
				value = 1;
			}
		}
	}
	return (value);
}
