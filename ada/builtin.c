#include "main.h"


void handle_user_input(void)
{
        char *tokens[MAX_TOKENS];
        int should_exit;

        char *input = NULL;

        should_exit = 0;

        while (!should_exit)
        {
                read_input(input);
                tokenize_input(input, tokens);

                if (strcmp(tokens[0], "exit") == 0)
                        should_exit = 0;
                else if (strcmp(tokens[0], "cd") == 0)
                {
                        if (tokens[1] != NULL)
                                chdir(tokens[1]);
                        else
                                perror("cd");
                }
                else
                {
                        execute_command(tokens);
                }
        }
}
