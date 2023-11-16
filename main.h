#ifndef _MAIN_H_
#define _MAIN_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <dirent.h>
#include <stddef.h>
#include <ctype.h>
#include <signal.h>

/* shell.c */
int call_shell(void);
void execute_command(char *);

/* string.c*/
void showchar(const char *str);
int compare(const char *, const char *);
int my_strncmp(const char *, const char *, size_t n);

/* cmd_handler.c*/
void ctrl_c(int signum);

/* functions1.c*/
int custom_execvp(const char *, char *const argv[]);
char *_getline(char *, int, int);
char *my_strdup(const char *);

/*env.c*/
char *my_getenv(const char *);
char *my_strchr(const char *, int);
int my_tolower(int);

/*functions2.c*/
void my_snout(char *, size_t, const char *, const char *);
int custom_execvp(const char *, char *const args[]);
int my_execvp2(const char *, char *const args[]);

/*non_shell.c*/
int non_shell2(int);

/*cd.c*/
int my_cd2(char *);
int my_cd(char *);
int change_dir(char *);

#endif
