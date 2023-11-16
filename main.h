#ifndef SHELL_H
#define SHELL_H
#define BUFFER_BYTES 1024
#define COMMAND_BYTES 512

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <dirent.h>

extern char **environ;

void current_directory(char *current_dir);
int isCd(char *argv[], char *args[], int bugCount);
int change_directory(char *args[], char *argv[],
char *prev_dir, int error_count);
int handleBuiltInCommands(char *args[], char **env);
int handleCmd(char *args[], char **env, char *argv[], int cmdCount);
void setEnvironmentVariable(char *variable, char *value);
void unsetEnvironmentVariable(char *variable, char ***env);
void displayPrompt(void);
void EnviromentLog(char **envc);
char *paths_Searcher(const char *input);
void clearBuffer(char *buffer[], int size);

char *_strtok(char *__s, const char *__delim);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

int change_directory(char *args[], char *argv[],
char *prev_dir, int error_count);
int cd_handler(char *args[], char *argv[], int argCount, int error_count);

#endif
