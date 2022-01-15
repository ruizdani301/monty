#define _GNU_SOURCE
#include "monty.h"
#include <stdlib.h>

/**
 * main - entry point
 * @argc: int variable
 * @argv: char variable
 *
 * Return: 0
*/

int main(int argc, char **argv)
{
	stack_t *st = NULL;
	char *buffer = NULL;
	size_t buff_size = 0;
	int line_count = 0;
	ssize_t line_size = 0;
	FILE *monty_file = NULL;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	monty_file = read_file(argv[1]);

	while ((line_size = getline(&buffer, &buff_size, monty_file)) != -1)
	{
		line_count++;
		if (buffer[0] != '#')
			is_opcode(buffer, &st, line_count);
	}

	free(buffer);
	freestack(&st);
	fclose(monty_file);
	return (0);
}

/**
 * parse - entry point
 * @buffer: char variable
 *
 * Return: cmds
*/

char **parse(char *buffer)
{
	char **cmds, *cmd, *delim;
	int i = 0;

	delim = "\t\n ";
	cmds = malloc(sizeof(char *) * 3);
	if (cmds == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	cmd = strtok(buffer, delim);
	while (cmd != NULL && i < 2)
	{
		cmds[i] = cmd;
		cmd = strtok(NULL, delim);
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

/**
 * is_opcode - entry point
 * @buff: char variable
 * @st: stack_t variable
 * @ln: unsigned int variable
*/

void is_opcode(char *buff, stack_t **st, unsigned int ln)
{
	char **cmds;
	instruction_t opts[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"nop", nop}, {"add", add}, {"sub", sub},
		{"div", _div}, {"pstr", pstr}, {NULL, NULL}
	};
	int i = 0, j = 0, len, b = 0, len2;

	cmds = parse(buff);
	while (cmds[i] != NULL)
	{
		j = 0;
		while (opts[j].opcode != NULL)
		{
			len = strlen(opts[j].opcode);
			len2 = strlen(cmds[i]);
			if (strncmp(opts[j].opcode, cmds[i], len) == 0 &&
					strncmp(opts[j].opcode, cmds[i], len2) == 0)
			{ b = 1;
				if (j == 0)
					check_push(st, cmds, ln);
				else
					opts[j].f(st, ln);
				break; }
			j++;
		}
		if (b == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, cmds[i]);
			free(cmds), freestack(st);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free(cmds);
}

/**
 * check_push - entry point
 * @st: stack_t variable
 * @cmds: char variable
 * @ln: unsigned int
*/

void check_push(stack_t **st, char **cmds, unsigned int ln)
{
	int i = 0, b = 0;
	char *cmds1;

	if (cmds[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free(cmds), freestack(st);
		exit(EXIT_FAILURE);
	}
	cmds1 = cmds[1];
	while (cmds1[i] != '\0')
	{
		if (cmds1[0] == '-' && b == 0)
			i++, b = 1;
		if (_isdigit(cmds1[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			free(cmds), freestack(st);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	push(st, atoi(cmds1));
}
/**
 * read_file - entry point
 * @file_name:  variable
 * Return: Variable
*/
FILE *read_file(char *file_name)
{
	FILE *fp = NULL;

	fp = fopen(file_name, "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
