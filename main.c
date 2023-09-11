#include "shell.h"

/**
 * sig_handler - Handles the ^C signal interupt.
 * @sig_handler: The signal handler func.
 *
 * Return:  The  func does not return a value (void).
 */
void sig_handler(int sig_handler)
{
	(void) sig_handler;
	_puts("\n$ ");
}

/**
 * main - The main func for the shell.
 * @argc: The num of arguments passed to main.
 * @argv:An array of arguments passed to main.
 * @environment: An array of environment variables.
 *
 * Return: 0 on success or the exit status code, or '?'.
 */
int main(int argc, char **argv, char **environment)
{
	size_t buffer = 0;
	unsigned int interactive = 0, i;
	input_t inputs = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	UNUSED(argc);

	inputs.argv = argv;
	inputs.env = init_env(environment);
	signal(SIGINT, sig_handler);
	if (!isatty(STDIN_FILENO))
		interactive = 1;
	if (interactive == 0)
		_puts("$ ");

	while (getline(&(inputs.buffer), &buffer, stdin) != -1)
	{
		inputs.count++;
		inputs.commands = tokenize(inputs.buffer, ";");
		for (i = 0; inputs.commands && inputs.commands[i] != NULL; i++)
		{
			inputs.tokens = tokenize(inputs.commands[i], "\n \t\r");
			if (inputs.tokens && inputs.tokens[0])
				if (_builtins(&inputs) == NULL)
					check_path(&inputs);
			free(inputs.tokens);
		}
		free(inputs.buffer);
		free(inputs.commands);
		if (interactive == 0)
			_puts("$ ");
		inputs.buffer = NULL;
	}
	if (interactive == 0)
		_puts("\n");
	free_environ(inputs.env);
	free(inputs.buffer);
	exit(inputs.status);
}
