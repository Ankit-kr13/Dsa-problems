#include <stdio.h>
#include <stdlib.h>
void fill(int *a, int size)
{
    printf("enter %d numbers\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (a + i));
    }
}
void sort(int *a, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (*(a + (j + 1)) < *(a + j))
            {
                temp = *(a + j);
                *(a + j) = *(a + (j + 1));
                *(a + (j + 1)) = temp;
            }
        }
    }
}
void display(int *a, int size)
{
    printf("\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(a + i));
    }
}
int main()
{
    int *a, size;
    printf("enter size of array : ");
    scanf("%d", &size);
    a = (int *)malloc(size * sizeof(int));
    fill(a, size);
    printf("original array\n");
    display(a, size);
    sort(a, size);
    printf("sorted array\n");
    display(a, size);
    free(a);
    return 0;
}