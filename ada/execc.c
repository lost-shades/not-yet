#include "main.h"

void execute_command(char *tokens[])
{
    int status;
    pid_t pid = fork();

    if (pid == 0)
    {
        char *command_path = get_command_path(tokens[0]);

        if (command_path != NULL)
        {
            execve(command_path, tokens, NULL);
            perror("execve");
            free(command_path);
            exit(EXIT_FAILURE);
        }
        else
        {
            write(STDERR_FILENO, "command not found\n", 18);
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("fork");
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

