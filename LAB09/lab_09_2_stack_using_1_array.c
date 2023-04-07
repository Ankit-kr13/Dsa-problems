#include <stdio.h>
#include <stdlib.h>
void push(int *top1, int *top2, int *a, int size)
{
    int b;
    printf("press 1 to push in stack 1\npress 2 to push in stack 2\n");
    scanf("%d", &b);
    switch (b)
    {
    case 1:
        if (*top1 + 1 == *top2)
        {
            printf("\nstack is full\n");
        }
        printf("\nenter the data to be pushed : ");
        *top1 += 1;
        scanf("%d", &a[*top1]);
        break;
    case 2:
        if (*top1 + 1 == *top2)
        {
            printf("\nstack is full\n");
        }
        printf("\nenter the data to be pushed : ");
        *top2 -= 1;
        scanf("%d", &a[*top2]);
        break;
    default:
        break;
    }
}
int pop(int *top1, int *top2, int *a, int size)
{
    int b, x;
    printf("press 1 to push in stack 1\npress 2 to push in stack 2\n");
    scanf("%d", &b);
    switch (b)
    {
    case 1:
        if (*top1 == -1)
        {
            printf("\nstack1 is empty\n");
            return -99;
        }
        printf("\nenter the data to be pushed : ");
        x = a[*top1];
        *top1 -= 1;
        break;
    case 2:
        if (*top2 == size)
        {
            printf("\nstack2 is empty\n");
            return -99;
        }
        printf("\nenter the data to be pushed : ");
        x = a[*top2];
        *top2 += 1;
        break;
    default:
        break;
    }
    return x;
}
void display(int top1, int top2, int *a, int size)
{
    int i;
    if (top1 == -1)
    {
        printf("\nstack1 is empty\n");
        return;
    }
    printf("\ncontents of stack 1 are\n");
    for (i = top1; i >= 0; i--)
    {
        printf("| %d |\n", a[i]);
    }
    printf("-----\n");
    if (top1 == size)
    {
        printf("\nstack2 is empty\n");
        return;
    }
    printf("\ncontents of stack 2 are\n");
    for (i = top2; i < size; i++)
    {
        printf("| %d |\n", a[i]);
    }
    printf("-----\n");

}
int main()
{
    int size, *a, top1, top2;
    int n, i,x;
    printf("enter size of array : \n");
    scanf("%d", &size);
    a = (int *)malloc(size * sizeof(int));
    top1 = -1;
    top2 = size;
    printf("\nenter number of elements you want to push in the stack : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        push(&top1, &top2, a, size);
    }
    printf("\nenter number of elements you want to pop from the stack : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        x = pop(&top1, &top2, a, size);
        if (x == -1)
        {
            break;
        }
        printf("\nvalue poped from stack is %d", x);
    }
    display(top1, top2, a, size);
    return 0;
}