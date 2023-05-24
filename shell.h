#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>

#define COMMAND_PROMPT "#KIMBA_REBEL$ "
#define UNUSED __attribute__((unused))
#define B_SIZ 1024

/*===== include structures =====*/
#include "structures.h"

/*===== include builtins =====*/
#include "object.h"

/*==== include helper functions =====*/
#include "functions.h"

void kimba(_st *nick, int arc, char *argv[], char **env);
void muturi(char *prompt, _st *nick);
void ctrl_c_hndl(int opr UNUSED);
int lgc_ops(char *array_commands[], int i, char array_operators[]);
void var_exp(_st *nick);
void alias_exp(_st *nick);
int add_buf(char *buffer, char *str_to_add);
void _token(_st *nick);
int _execve(_st *nick);
int blt_in_lst(_st *nick);
int p_alias(_st *nick, char *alias);
char *alias_get(_st *nick, char *alias);
int set_alias(char *alias_string, _st *nick);
char **_tok(_st *nick);
int prog_fnd(_st *nick);

/* Help information display macros */
#define CD_HELP_INFO "cd=\n"\
"cd: cd [dir]"\
"\n\tChange the pwd"\
"\n\tNULL arguments to be treated as cd HOME"\
"\n\tif argument is \"-\", the command changes the pwd"\
"\n\tto previous pwd"

#define EXIT_HELP_INFO "exit=\n"\
"exit: exit [STATUS]"\
"\n\tQuit the shell with a specified status code"\
"\n\tIf no status code is provided, the exit status code"\
"\n\twill be the same as that of the last executed command"

#define ENVIRONMENT_HELP_INFO "env=\n"\
"env: env"\
"\n\tDisplay a complete list of environment variables"\
"\n\tthat are currently set"

#define SETENV_HELP_INFO "setenv=\n"\
"setenv: setenv [VARIABLE VALUE]"\
"\n\tAdd or modify an environment variable"\
"\n\tIf an incorrect number of arguments is provided"\
"\n\tan error message will be displayed"

#define UNSETENV_HELP_INFO "unsetenv=\n"\
"unsetenv: unsetenv [VARIABLE]"\
"\n\tRemove an environment variable"\
"\n\tIf an incorrect number of arguments is provided,"\
"\n\tan error message will be displayed."

#define HELP_INFO_SEARCH "help=\n"\
"help: help [BUILTIN_CMD]"\
"\n\tDisplay information about built-in commands"\
"\n\tIf a specific command name is provided as an argument"\
"\n\tdetailed help for that command will be displayed"\
"\n\tIf no argument is provided, a list of available built-in commands will be displayed"

#endif
