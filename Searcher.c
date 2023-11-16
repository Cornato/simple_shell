#include "main.h"

/**
 * paths_Searcher - Searches for the specified executable file
 * @input: Number of arguments provided to the function.
 * Return: If the executable file is found.
 */

char *paths_Searcher(const char *input)
{
	char search_path[1024];
	char *env_paths, *env_copy;
	char *ary;
	struct stat stats;

	env_paths = getenv("PATH");

	if (env_paths == NULL)
		return (NULL);

	env_copy = strdup(env_paths);

	if (env_copy == NULL)
		return (NULL);

	for (ary = _strtok(env_copy, ":"); ary != NULL; ary = _strtok(NULL, ":"))
	{
		_strcpy(search_path, ary);
		strcat(search_path, "/");
		strcat(search_path, input);

		if (stat(search_path, &stats) == 0)
		{
			free(env_copy);
			return (strdup(search_path));
		}
	}
	free(env_copy);
	return (NULL);
}
