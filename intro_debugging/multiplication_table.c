#include <stdio.h>

void print_table(int size)
{
    int row, col;

    for (col = 1; col <= size; col++)
    {
        for (row = 1; row <= size; row++)
        {
            printf("%d ", row * col);
        }
        printf("\n");
    }
}

/* -- DO NOT Modify the code below this line -- */

int main(void)
{
    print_table(4);
    return 0;
}