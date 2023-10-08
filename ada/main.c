#include "main.h"

void read_input(char *input)
{
	size_t input_size = 0;
	ssize_t user_input;
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, 2);

	user_input = getline(&input, &input_size, stdin);

	if (user_input == -1)
	{
		perror("Error in user input");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	while(1)
	{
		handle_user_input();
	}
	return (0);
}

