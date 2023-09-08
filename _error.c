#include "shell.h"

/**
 * _error - Outputs error messages to the standard error stream.
 *
 * @inputs: Pointer to a structure containing relevant variables.
 * @message: The message to be printed as an error.
 *
 * Return: This function does not return a value (void).
 */

void _error(input_t *inputs, char *message)
{
	char *count;

	_printer(inputs->argv[0]);
	_printer(": ");
	count = _int_str(inputs->count);
	_printer(count);
	free(count);
	_printer(": ");
	_printer(inputs->tokens[0]);
	if (message)
	{
		_printer(message);
	}
	else
		perror("");
}
