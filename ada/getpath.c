#include "main.h"

char *get_command_path(char *command) {
    char *path = getenv("PATH");
    char *path_copy;
    char *path_token;
    char *command_path;
    size_t command_length;
    size_t path_length;
     struct stat buffer;

    if (path == NULL) {
        fprintf(stderr, "Error: PATH environment variable not set.\n");
        return NULL;
    }

    path_copy = strdup(path);
    if (path_copy == NULL) {
        perror("strdup");
        return NULL;
    }

    path_token = strtok(path_copy, ":");
    while (path_token != NULL) {
        path_length = strlen(path_token);
        command_length = strlen(command);

        command_path = (char *)malloc(path_length + command_length + 2);
        if (command_path == NULL) {
            perror("malloc");
            free(path_copy);
            return NULL;
        }

        strcpy(command_path, path_token);
        strcat(command_path, "/");
        strcat(command_path, command);

        if (stat(command_path, &buffer) == 0) {
            free(path_copy);
            return command_path;
        } else {
            free(command_path);
            path_token = strtok(NULL, ":");
        }
    }

    free(path_copy);
    return NULL;
}

