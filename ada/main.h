#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_TOKENS 100

void read_input(char *input);
void tokenize_input(char *input, char *tokens[]);
void execute_command(char *tokens[]);
void handle_user_input(void);
char *get_command_path(char *command);
