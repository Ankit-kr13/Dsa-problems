#include <stdio.h>
#include <stdlib.h>
#define n 7

int deque_arr[n];
int front = -1;
int rear = -1;

void insert_frontEnd(int item);
void insert_rearEnd(int item);
int delete_frontEnd();
int delete_rearEnd();
void display();
int isEmpty();
int isFull();

void insert_frontEnd(int item)
{
    if (isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if (front == -1)

    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = n - 1;
    else
        front = front - 1;
    deque_arr[front] = item;
}

void insert_rearEnd(int item)
{
    if (isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if (front == -1)

    {
        front = 0;
        rear = 0;
    }
    else if (rear == n - 1)
        rear = 0;
    else
        rear = rear + 1;
    deque_arr[rear] = item;
}

int delete_frontEnd()
{
    int item;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    item = deque_arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == n - 1)
        front = 0;
    else
        front = front + 1;
    return item;
}

int delete_rearEnd()
{
    int item;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    item = deque_arr[rear];

    if (front == rear)

    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = n - 1;
    else
        rear = rear - 1;
    return item;
}

int isFull()
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue elements :\n");
    i = front;
    if (front <= rear)
    {
        while (i <= rear)
            printf("%d ", deque_arr[i++]);
    }
    else
    {
        while (i <= -1)
            printf("%d ", deque_arr[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", deque_arr[i++]);
    }
    printf("\n");
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n\n1.Insert at the front end\n");
        printf("2.Insert at the rear end\n");
        printf("3.Delete from front end\n");
        printf("4.Delete from rear end\n");
        printf("5.Display\n");
        printf("6.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nInput the element for adding in queue : ");
            scanf("%d", &item);
            insert_frontEnd(item);
            break;
        case 2:
            printf("\nInput the element for adding in queue : ");
            scanf("%d", &item);
            insert_rearEnd(item);
            break;
        case 3:
            printf("\nElement deleted from front end is : %d\n", delete_frontEnd());
            break;
        case 4:
            printf("\nElement deleted from rear end is : %d\n", delete_rearEnd());
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
        default:
            printf("\nWrong choice\n");
        }
        printf("\nfront = %d, rear =%d\n", front, rear);
        display();
    }
}
