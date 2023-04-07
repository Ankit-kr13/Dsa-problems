#include <stdio.h>

#include <stdlib.h>
void fill(int *a, int size)
{
    printf("enter %d numbers\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}
void insertion_sort(int *a, int size)
{
    int i, j, c, k;
    for (i = 1; i < size; i++)
    {
        c = a[i];
        for (j = 0; j < i; j++)
        {
            if (a[j] > c)
            {
                break;
            }
        }
        for (k = i; k > j; k--)
        {
            a[k] = a[k - 1];
        }
        a[k] = c;
    }
}
void display(int *a, int size)
{
    printf("\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}
int main()
{
    int *a, size;
    printf("enter size of array : ");
    scanf("%d", &size);
    a = (int *)malloc(size * sizeof(int));
    fill(a, size);
    printf("Given array");
    display(a, size);
    insertion_sort(a, size);
    printf("Sorted array");
    display(a, size);
    free(a);
    return 0;
}