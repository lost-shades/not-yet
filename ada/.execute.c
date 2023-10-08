#include "main.h"

void execute_command(char *tokens[])
{
        int status;
        pid_t pid = fork();

        if (pid == 0)
        {
                char *env_path;
                char *path;
                size_t path_size = strlen(tokens[0]) + strlen("/bin/") + 1;
                char *command_path;

                command_path = malloc(path_size * sizeof(char));
                env_path = getenv("PATH");
                path = strtok(env_path, ":");

                while (path != NULL)
                {
                        strcpy(command_path, path);
                        strcat(command_path, "/");
                        strcat(command_path, tokens[0]);

                        if (access(command_path, F_OK | X_OK) == 0)
                        {
                                execve(command_path, tokens, NULL);
                                perror("execve");
                                free(command_path);
                                exit(EXIT_FAILURE);
                        }
                        path = strtok(NULL, ":");
                }
                write(STDERR_FILENO, "command not found\n", 18);
                exit(EXIT_FAILURE);
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
