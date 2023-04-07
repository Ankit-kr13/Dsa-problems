#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *a;
};
struct stack s;
void creation()
{
    printf("enter size of the stack : ");
    scanf("%d", &s.size);
    s.top = -1;
    s.a = (int *)malloc(s.size * sizeof(int));
}
int isempty()
{
    if (s.top == -1)
    {
        return 1;
    }
    return 0;
}
int push()
{
    if (s.top == s.size - 1)
    {
        printf("\nstack is full\n");
        return 1;
    }
    printf("\nenter the data to be pushed : ");
    scanf("%d", &s.a[s.top + 1]);
    s.top += 1;
    return 0;
}
int pop()
{
    int x;
    if (isempty())
    {
        printf("\nstack is empty\n");
        return -1;
    }
    x = s.a[s.top];
    s.top -= 1;
    return x;
}
void display()
{
    printf("\n");
    if (isempty())
    {
        printf("\nstack is empty\n");
        return;
    }
    int i;
    printf("\ncontents of stack are\n");
    for (i = s.top; i >= 0; i--)
    {
        printf("| %d |\n", s.a[i]);
    }
    printf("-----");
}
int main()
{
    creation();
    int i, n, x, a;
    char ch = 'y';
    while (ch == 'y')
    {
        printf("\npress 1 to push\npress 2 to pop\npress 3 to check whether stck is empty or not\npress 4 to display the contents of the stack\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("\nenter number of elements you want to push in the stack : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                if(push())
                {
                    break;
                }
            }
            break;
        case 2:
            printf("\nenter number of elements you want to pop from the stack : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                x = pop();
                if (x == -1)
                {
                    break;
                }
                printf("value poped from stack is %d\n", x);
            }
            break;
        case 3:
            if (isempty())
            {
                printf("\nstack is empty\n");
            }
            else
            {
                printf("\nstack is not empty\n");
            }
            break;
        case 4:
            display();
            break;
        default:
            printf("\ninvalid input\n");
        }
        printf("\ndo want to continue(y/n): ");
        scanf(" %c", &ch);
    }
    return 0;
}