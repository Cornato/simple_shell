#include "main.h"
/**
 * displayPrompt - Displays command prompt if the standard input is a terminal.
 * Return: This function does not return a value.
 */
void displayPrompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("(->) ");
}

/**
 * handleBuiltInCommands - Handles built-in shell commands.
 * @args: Array of command arguments.
 * @env: Environment variables array.
 * Return: 1 if a built-in command is processed, 0 otherwise.
 */
int handleBuiltInCommands(char *args[], char **env)
{
	if (args[0] == NULL || *args[0] == '\0')
	{
		return (0);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		EnviromentLog(env);
		return (1);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		char *variable = args[1];
		char *value = args[2];

		if (variable != NULL && *variable != '\0' && value != NULL)
		{
			setEnvironmentVariable(variable, value);
			return (1);
		}
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		char *variable = args[1];

		if (variable != NULL && *variable != '\0')
		{
			unsetEnvironmentVariable(variable, &env);
			return (1);
		}
	}

	return (0);
}

/**
 * handleCmd - Executes a shell command in a separate process.
 * @args: Array of command arguments.
 * @env: Environment variables array.
 * @argv: Command-line arguments array.
 * @cmdCount: Command count.
 * Return: Exit status of the executed command.
 */
int handleCmd(char *args[], char **env, char *argv[], int cmdCount)
{
	pid_t pid;
	int output = 0, details = 0;
	int shouldSearchPath = (args[0][0] != '/' || args[0][0] != '.');

	pid = fork();
	if (pid == -1)
	{
		perror("pid");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *values = NULL;

		if (shouldSearchPath)
			values = paths_Searcher(args[0]);
		if (values == NULL)
			values = args[0];
		if (execve(values, args, env) == -1)
			output = 127;
		fprintf(stderr, "%s: %d: %s: not found\n", argv[0], cmdCount, args[0]);
	}
	else
	{
		waitpid(pid, &details, 0);
		if (WIFEXITED(details))
			output = WEXITSTATUS(details);
		else if (WIFSIGNALED(details))
			output = WTERMSIG(details);
	}
	return (output);
}

/**
 * main - Simple shell main function.
 * @ac: Number of command-line arguments.
 * @argv: Command-line arguments array.
 * Return: Exit status of the simple shell.
 */
int main(int ac, char *argv[])
{
	char user_Input[COMMAND_BYTES];
	char *Splits;
	char *args[COMMAND_BYTES];
	int splitCounter = 0, bugCount = 0, value = 0;
	size_t user_input_len;
	(void)ac;

	for (;;)
	{
		displayPrompt();
		if (fgets(user_Input, sizeof(user_Input), stdin) == NULL)
			break;
		bugCount++;
		user_input_len = _strlen(user_Input);
		if (user_input_len > 0 && user_Input[user_input_len - 1] == '\n')
			user_Input[user_input_len - 1] = '\0';

		for (Splits = strtok(user_Input, " "); Splits != NULL;
		     Splits = strtok(NULL, " "))
			args[splitCounter++] = Splits;

		args[splitCounter] = NULL;
		if (splitCounter > 0)
		{
			if (_strcmp(args[0], "cd") == 0)
			{
				cd_handler(args, argv, splitCounter, bugCount);
				clearBuffer(args, COMMAND_BYTES);
				splitCounter = 0;
				continue;
			}
			if (_strcmp(args[0], "exit") == 0)
				break;
			if (handleBuiltInCommands(args, environ) == 0)
				value = handleCmd(args, environ, argv, bugCount);
		}
		splitCounter = 0;
		clearBuffer(args, COMMAND_BYTES);
	}
	return (value);
}
