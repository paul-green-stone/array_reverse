#include <stdio.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

void inplace_swap(int* x, int* y);

void reverse_array(int* array, size_t a_size);

void print_array(int* array, size_t a_size);

int main(int argc, char* argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    fprintf(stdout, "Before calling the function: ");
    print_array(array, ARRAY_SIZE(array));

    reverse_array(array, ARRAY_SIZE(array));

    fprintf(stdout, "After calling the function: ");
    print_array(array, ARRAY_SIZE(array));

    return 0;
}

void inplace_swap(int* x, int* y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int* array, size_t a_size)
{
    for (int i = 0, j = a_size - 1; i < j; i++, j--)
        inplace_swap((array + i), (array + j));
}

void print_array(int* array, size_t a_size)
{
    fprintf(stdout, "[");
    for (int i = 0; i < a_size; i++)
    {
        fprintf(stdout, "%d", *(array + i));

        if (i + 1 != a_size)
            fprintf(stdout, ", ");
    }
    fprintf(stdout, "]\n");
}