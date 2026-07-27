#include "3-calc.h"

/**
 * main - performs simple mathematical operations
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exits with status 98, 99, or 100 on error
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	char *op;
	int (*func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);

	func = get_op_func(op);

	if (func == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((*op == '/' || *op == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = func(num1, num2);
	printf("%d\n", result);

	return (0);
}
