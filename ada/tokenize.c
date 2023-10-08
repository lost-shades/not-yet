#include "main.h"


void tokenize_input(char *input, char *tokens[])
{
	char *input_copy;
	char *token;
	int i;
	
	i = 0;

	if (input == NULL)
		return;
	input_copy = strdup(input);
	token = strtok(input_copy, " \t\n");
	
	if (input_copy == NULL)
		return;

	while (token != NULL && i < MAX_TOKENS)
	{
		tokens[i] = token;
		i++;
		
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	free(input_copy);
}
