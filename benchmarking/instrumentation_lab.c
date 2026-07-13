#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state = SEED_VALUE;
    int i;
    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i, v;
    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0) v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum = 0;
    int i;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];
    return sum;
}

int main(void)
{
    clock_t t1, t2, t3, t4;
    double t_build, t_process, t_reduce, t_total;

    t1 = clock();
    build_dataset();
    t2 = clock();
    process_dataset();
    t3 = clock();
    reduce_checksum();
    t4 = clock();

    t_build = (double)(t2 - t1) / CLOCKS_PER_SEC;
    t_process = (double)(t3 - t2) / CLOCKS_PER_SEC;
    t_reduce = (double)(t4 - t3) / CLOCKS_PER_SEC;
    t_total = (double)(t4 - t1) / CLOCKS_PER_SEC;

    printf("TOTAL seconds: %.6f\n", t_total);
    printf("BUILD_DATA seconds: %.6f\n", t_build);
    printf("PROCESS seconds: %.6f\n", t_process);
    printf("REDUCE seconds: %.6f\n", t_reduce);

    return 0;
}
