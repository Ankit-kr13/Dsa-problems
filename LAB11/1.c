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
void display(int *a, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int n, *a, x;
    printf("enter size of array : ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    fill(a, n);
    printf("original array\n");
    display(a, n);
    printf("\npress 1 to use selction sort\npress 2 to use insertion sort\npress 3 to use merge sort\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        selection_sort(a, n);
        printf("sorted array using selection sort\n");
        display(a, n);
        break;
    case 2:
        insertion_sort(a, n);
        printf("sorted array using insertion sort\n");
        display(a, n);
        break;
    case 3:
        mergesort(a, 0, n);
        printf("sorted array using merge sort\n");
        display(a, n);
        break;
    default:
    {
        printf("invalid input\n");
    }
    }
    return 0;
}