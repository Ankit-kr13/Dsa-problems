#include <stdio.h>
#include <conio.h>
#define max 10
int stack[max];
int top = 0, x;
void push(int x)
{
    if (top >= max)
        printf("Stack is overflow\n");
    else
    {
        stack[top] = x;
        top++;
    }
}
int pop()
{
    if (top <= 0)
        printf("Stack is underflow\n");
    else
    {
        top--;
        x = stack[top];
    }
    return x;
}

void display()
{
    int i;
    i = top - 1;
    if (top == 0)
        printf("Stack is Empty");
    else
        printf("The Elments in Stack are \n");
    while (i >= 0)
    {
        printf(" %d\n", stack[i--]);
    }
}

int isempty()
{
    if (top == 0)
        return 1;
    else
        return 0;
}
int isfull()
{
    if (top == max)
        return 1;
    else
        return 0;
}
int peekhighest()
{
    int highest = stack[top - 1];
    for (int i = top - 1; i >= 0; i--)
    {
        if (highest < stack[i])
        {
            highest = stack[i];
        }
    }
    return highest;
}
int peeklowest()
{
    int lowest = stack[top - 1];
    for (int i = top - 1; i >= 0; i--)
    {
        if (lowest > stack[i])
        {
            lowest = stack[i];
        }
    }
    return lowest;
}
int peekmiddle()
{
    int size = 0;
    for (int i = top - 1; i >= 0; i--)
    {
        size += 1;
    }
    int middle = (size / 2 + 1);
    return middle;
}
void main()
{
    int ch, item, d;
    char run;
    printf("\n1.PUSH");
    printf("\n2.POP");
    printf("\n3.Display");
    printf("\n4.isempty");
    printf("\n5.isfull");
    printf("\n6.peekhighest");
    printf("\n7.peeklowest");
    do
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter an Element to PUSH: \n");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            x = pop();
            printf("The element POP out from Stack is %d\n", x);
            break;
        case 3:
            display();
            break;
        case 4:
            x = isempty();
            if (x == 1)
                printf("Stack is Empty");
            else
                printf("Stack is Not Empty");
            break;
        case 5:
            x = isfull();
            if (x == 1)
                printf("Stack is Full");
            else
                printf("Stack is Not Full");
            break;
        case 6:
            int h = peekhighest();
            printf("The highest element present in stack:%d\n", h);
            break;
        case 7:
            int l = peeklowest();
            printf("The lowest element present in stack:%d\n", l);
            break;
        case 8:
            int m = peekmiddle();
            printf("The middle element present in stack:%d\n", m);
            break;
        default:
            printf("INVALID Choice\n");
        }
        printf("Do u want to continue y/n: ");
        scanf(" %c", &run);
    } while ((run == 'y') || (run == 'Y'));
    getch();
}