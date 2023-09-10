#include "shell.h"

/**
 * _strcat - two strings concatenates
 * @dest: first string
 * @src: second string
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	char *new;
	unsigned int len1, len2, len, i, j;

	len1 = 0;
	len2 = 0;
	if (dest == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; dest[len1]; len1++)
			;
	}
	if (src == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; src[len2]; len2++)
			;
	}
	len = len1 + len2 + 2;
	new = malloc(len * sizeof(char));
	if (new == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		new[i] = dest[i];
	new[i] = '/';
	for (j = 0; j < len2; j++)
		new[i + 1 + j] = src[j];
	new[len1 + len2 + 1] = '\0';
	return (new);
}


/**
 * _strlen - returns length string
 * @s: measured string
 * Return: string length
 */
unsigned int _strlen(char *s)
{
	unsigned int len;

	len = 0;

	for (len = 0; s[len]; len++)
		;
	return (len);
}

/**
 * _strncmp - two strings compares
 * @s1: compared in length first string, of two
 * @s2: compared second string, of two
 * Return: if success 0, else failure
 */
int _strncmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strdup - pointer to new mem alloc space
 * @duplicate: duplicate string
 * Return: pointer to new string duplicate
 */
char *_strdup(char *duplicate)
{
	char *copy;
	int len, i;

	if (duplicate == 0)
		return (NULL);

	for (len = 0; duplicate[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = duplicate[i];

	return (copy);
}

/**
 * _puts - string to standard output
 * @s: write string
 *
 * Return: chars printed or -1 if failure
 */
ssize_t _puts(char *s)
{
	ssize_t num, len;

	num = _strlen(s);
	len = write(STDOUT_FILENO, s, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
