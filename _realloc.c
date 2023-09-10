#include "shell.h"

/**
 * _realloc - pointer reallocate to double space
 * @ptr: pointer old array
 * @size: pointer to number elements in old array
 *
 * Return: pointer new array
 */
char **_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t i;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		new[i] = ptr[i];
	}
	*size += 10;
	free(ptr);
	return (new);
}
