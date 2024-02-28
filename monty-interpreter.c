#include "monty.h"
#include <stdio.h>
#include <stddef.h>

/**
 * read_file - reads a file and executes the commands
 * @filename: the file to read
 * @stack: the stack
*/
void read_file(char *filename, stack_t **stack)
{
	char *line;
	size_t len = 0;
	int line_count = 1;
	int check;
	int read;
	instruct_func f;

	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &len, var_global.file)) != -1)
	{
		line = parse_line(var_global.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		f = get_op_func(line);
		if (f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		f(stack, line_count);
		line_count++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}


/**
 * isnumber - checks if a string is a number
 * @str: the string to check
 * Return: 1 if the string is a number, 0 otherwise
*/
int isnumber(char *str)
{
	unsigned int i = 0;

	if (str == NULL)
		return (0);

	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * get_op_func - selects the correct function to perform the operation
 * @opcode: the operation code
 * Return: pointer to the function that corresponds to the opcode
*/

instruct_func get_op_func(char *opcode)
{
	instruction_t instructs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (instructs[i].opcode)
	{
		if (strcmp(opcode, instructs[i].opcode) == 0)
			return (instructs[i].f);
		i++;
	}
	return (NULL);

	/**
	 * while (instructs[i].f != NULL && strcmp(opcode,
	 * instructs[i].opcode) != 0)
	 * { i++; }
	 * return (instructs[i].f);
	*/
}

/**
 * parse_line - parses a line and gets the opcode and argument
 * @line: the line to parse
 * @stack: the stack
 * @line_number: the line number
 * Return: the opcode
*/

char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *push, *arg;
	(void)stack;

	push = "push";
	opcode = strtok(line, " \n ");
	if (opcode == NULL)
		return (NULL);

	if (strcmp(opcode, push) == 0)
	{
		arg = strtok(NULL, " \n");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
		   fprintf(stderr, "L%d: usage: push integer\n", line_number);
		   exit(EXIT_FAILURE);
		}
	}
	return (opcode);
}
