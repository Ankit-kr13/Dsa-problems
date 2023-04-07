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
int peekhighest()
{
    int i, m;
    m = s.a[0];
    for (i = 1; i <= s.top; i++)
    {
        if (s.a[i] > m)
        {
            m = s.a[i];
        }
    }
    return m;
}
int peeklowest()
{
    int i, m;
    m = s.a[0];
    for (i = 1; i <= s.top; i++)
    {
        if (s.a[i] < m)
        {
            m = s.a[i];
        }
    }
    return m;
}
int peekmiddle()
{
    int i, m, n, j;
    n = (s.size / 2) + 1;
    int arr[n];
    arr[0] = peeklowest();
    for (i = 1; i < n; i++)
    {
        arr[i] = peekhighest();
        for (j = 0; j <= s.top; j++)
        {
            if (s.a[j] < arr[i] && s.a[j] > arr[i - 1])
            {
                arr[i] = s.a[j];
            }
        }
    }
    return arr[n-1];
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
        printf("\npress 1 to push\npress 2 to pop\npress 3 to check whether stck is empty or not\npress 4 to display the contents of the stack\npres 5 to get the highest value\npress 6 to gest lowest value\npress 7 to gest middle value\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("\nenter number of elements you want to push in the stack : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                if (push())
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
                    printf("value poped from stack is %d", x);
                    break;
                }
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
        case 5:
            if (isempty())
            {
                printf("\nstack is empty\n");
            }
            else
            {
                int m;
                m = peekhighest();
                printf("hightest value in the stack is %d", m);
            }
            break;
        case 6:
            if (isempty())
            {
                printf("\nstack is empty\n");
            }
            else
            {
                int m;
                m = peeklowest();
                printf("lowest value in the stack is %d", m);
            }
            break;
            case 7:
            if (isempty())
            {
                printf("\nstack is empty\n");
            }
            else
            {
                int m;
                m = peekmiddle();
                printf("middle value in the stack is %d", m);
            }
            break;
        default:
            printf("\ninvalid input\n");
        }
        printf("\ndo want to continue(y/n): ");
        scanf(" %c", &ch);
    }
    return 0;
}