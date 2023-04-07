#include <stdio.h>
#include <stdlib.h>
int main()
{
    int b;
    printf("press 1 to create a array or 0 to exit\n");
    scanf("%d", &b);
    switch (b)
    {
    case 1:
    {
        int *a, n, i;
        printf("enter the number of elements you want to enter in array : ");
        scanf("%d", &n);
        a = (int *)malloc(100 * sizeof(int));
        printf("enter %d numbers\n", n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("\npress 1 to print the array\npress 2 to insert in array\npress 3 to delete from array\npress 0 to exit\n");
        scanf("%d", &b);
        switch (b)
        {
        case 1:
        {
            printf("\n");
            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            break;
        }
        case 2:
        {
            int position, data;
            printf("\nenter the position where you want to enter number : ");
            scanf("%d", &position);
            printf("\nenter the number you want to enter at position %d : ", position);
            scanf("%d", &position);
            for (i = n; i >= position; i--)
            {
                a[i + 1] = a[i];
            }
            a[position] = data;
            n++;
            printf("\narray after inserting the element\n");
            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            break;
        }
        case 3:
        {
            int position;
            printf("\nenter the position from where you want to delete the element : ");
            scanf("%d", &position);
            for (i = position; i < (n - 1); i++)
            {
                a[i] = a[i + 1];
            }
            n--;
            printf("\narray after deleting the element\n");
            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            printf("\ninvalid choice\n");
        }
        }
        break;
    }
    case 0:
    {
        return 0;
    }
    default:
    {
        printf("\ninvalid choice\n");
    }
    }
    return 0;
}