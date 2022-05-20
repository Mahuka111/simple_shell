#ifndef SHELL_H
#define SHELL_H

/* header files */
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

/* Global variable */
extern char **environ;

/* Macros */
#define BUFSIZE 256
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define PROMPT "$ "
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)

/* Struct */
#include <sys/types.h>

/**
 * struct sh_data - Global data structure
 * @line: the line input
 * @args: the arguments token
 * @error_msg: the global path
 * @cmd: the parsed command
 * @index: the command index
 * @oldpwd: the old path visited
 * @env: the environnment
 * struct error_msg - An structure for each error message
 *
 * Description: A structure contains all the variables needed to manage
 * the program, memory and accessability
 * @ecode: error code
 * @msg: pointer to error message
 * @size: error message length.
 */
typedef struct sh_data
typedef struct error_msg
{
	char *line;
	char **args;
	char *cmd;
	char *error_msg;
	char *oldpwd;
	unsigned long int index;
	char *env;
} sh_t;
	int ecode;
	char *msg;
	int  size;
} error_msg_t;

/**
 * struct builtin - Manage the builtin functions
 * @cmd: the command line on string form
 * @f: the associated function
 * struct built_s - Builtings commands
 * @command: command name.
 * @f: function to call.
 *
 * Description: this struct made to manage builtins cmd
 * Description: Longer description
 */
typedef struct builtin
typedef struct built_s
{
	char *cmd;
	int (*f)(sh_t *data);
} blt_t;
/* ----------Process prototype------------*/
int read_line(sh_t *);
int split_line(sh_t *);
int parse_line(sh_t *);
int process_cmd(sh_t *);
	char *command;
	void (*f)(char **);
} built_t;

/* ----------String prototype------------*/
char *_strdup(char *str);
char *_strcat(char *first, char *second);
int _strlen(char *str);
char *_strchr(char *str, char c);
int _strcmp(char *s1, char *s2);
/**
 * struct history - An structure for each command readed
 *
 * @id_h: error code
 * @comms: Commands
 * @prev: Previous element
 * @next: Next element
 */

/* ----------More String prototype-------*/
char *_strcpy(char *dest, char *source);
typedef struct history
{
	unsigned int id_h;
	char *comms;
	struct history *prev;
	struct history *next;
} history_t;

/* ----------Memory prototype------------*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char byt, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
int free_data(sh_t *);
/**
 * struct command_s - An structure for each command
 *
 * @command: command with arguments.
 * @next: pointer to next command.
 */
typedef struct command_s
{
	char **command;
	struct command_s *next;
} command_t;

/* Shell functions */
command_t **_prompt(char *, char *);
int _fork(char *, command_t *, char *, char **);
int _stat(char *, char *);
int _exec(char *, char **, char **);

/* ----------Tools prototype-------------*/
void *fill_an_array(void *a, int el, unsigned int len);
void signal_handler(int signo);
char *_getenv(char *path_name);
void index_cmd(sh_t *data);
void array_rev(char *arr, int len);
/* Utilities */
char *read_line(void);

/* ----------More tools prototype--------*/
char *_itoa(unsigned int n);
int intlen(int num);
int _atoi(char *c);
int print_error(sh_t *data);
int write_history(sh_t *data);
int _isalpha(int c);
size_t _strlen(char *str);
command_t *_parser_cmd(char *, char *);
size_t _parser_arg(char *, char **, size_t *);
void print_char_pointer_arr(char **, size_t);
int add_nodeint(history_t **head, char *str);
char *_strdup(char *str);
void free_listint(history_t *head);
void print_listint(const history_t *);
char *find_path(char **);
char *_strstr(char *haystack, char *needle);
void print_env(char **);
char *_which(char *p_rec, char *first_arg);
char *string_nconcat(char *s1, char *s2, unsigned int n);
int _strcmp(char *s1, char *s2);
void _exit_func(char **);
int verif_built_comm(char *str, char **env);

/* -------------Builtins-----------------*/
int abort_prg(sh_t *data);
int change_dir(sh_t *data);
int display_help(sh_t *data);
int handle_builtin(sh_t *data);
int check_builtin(sh_t *data);
/* Error handler */
void error_handler(char *, int);
void error_handler_set_default(int, char *);

/* -------------Parse-----------------*/
int is_path_form(sh_t *data);
void is_short_form(sh_t *data);
int is_builtin(sh_t *data);
/* Command Utilities */
command_t *new_cmd_node(char *);
void add_tok_to_cmd(char *, command_t *, size_t, char *);

#endif /* SHELL_H */
#endif
