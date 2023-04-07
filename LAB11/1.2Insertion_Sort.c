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
void display(int *a, int n)
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void sorted_merge(int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0, *c;
    c = (int *)malloc(((high - low) + 1) * sizeof(int));
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    k = 0;
    for (i = low; i <= high; i++)
    {
        a[i] = c[k];
        k++;
    }
}
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        sorted_merge(a, low, mid, high);
    }
}
int main()
{
    int n, *a;
    printf("enter the size of array\n");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    fill(a, n);
    printf("original array");
    display(a, n);
    mergesort(a, 0, n - 1);
    printf("\nsorted array");
    display(a, n);
    return 0;
}