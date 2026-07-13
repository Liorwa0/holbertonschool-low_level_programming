#include <stdio.h>
#include <time.h>

int main(void)
{
    clock_t start, end;
    double cpu_time_used;
    long i;

    start = clock();

    /* هنا نضع الكود الذي نريد قياسه */
    for (i = 0; i < 100000000; i++)
    {
        /* عملية حسابية بسيطة */
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", cpu_time_used);
    return (0);
}
