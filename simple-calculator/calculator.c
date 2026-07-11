#include <stdio.h>

int main(void)
{
	int choice, a, b, c;

	printf("Simple Calculator\n");
	while (1)
	{
		printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\nChoice: ");
		if (scanf(" %d", &choice) != 1)
		{
			printf("Invalid choice");
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
		if (choice < 1 || choice > 4)
		{
			printf("Invalid choice");
			continue;
		}
		printf("A: ");
		if (scanf(" %d", &a) != 1)
		{
			printf("Invalid number");
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		printf("B: ");
		if (scanf(" %d", &b) != 1)
		{
			printf("Invalid number");
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		if (choice == 1) printf("Result: %d\n", a + b);
		else if (choice == 2) printf("Result: %d\n", a - b);
		else if (choice == 3) printf("Result: %d\n", a * b);
		else if (choice == 4)
		{
			if (b == 0) printf("Division by zero\n");
			else printf("Result: %d\n", a / b);
		}
	}
	return (0);
}
