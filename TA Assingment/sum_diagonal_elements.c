#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size, i, j, sum = 0;
    printf("enter size of square matrix\n");
    scanf("%d", &size);
    int(*a)[size];
    a = (int(*)[size])malloc(size * size * sizeof(int));
    printf("\nenter %d number\n", size * size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("the 2-d array is\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if ((i == j) || ((i + j) == size - 1))
            {
                sum += a[i][j];
            }
        }
    }
    free(a);
    printf("\nsum of diagonal elements is : %d\n",sum);
    return 0;
}