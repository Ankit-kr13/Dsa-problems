#include <stdio.h>
#include <stdlib.h>
void fill(int *a, int n)
{
    printf("enter %d numbers\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void selection_sort(int *a, int n)
{
    int i, j, m, temp;
    for (i = 0; i < n - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[m])
            {
                m = j;
            }
        }
        temp = a[m];
        a[m] = a[i];
        a[i] = temp;
    }
}
void display(int *a, int n)
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int n, *a;
    printf("enter size of array : ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    fill(a, n);
    printf("original array\n");
    display(a, n);
    selection_sort(a, n);
    printf("sorted array\n");
    display(a, n);
    return 0;
}