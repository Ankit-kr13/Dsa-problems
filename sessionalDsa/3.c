#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev_862;
    int data;
    struct node *next;
};
struct node *head;
void addnodefirst(int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->prev_862 = NULL;
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    head->prev_862 = ptr;
    ptr->next = head;
    head = ptr;
}
void addnodelast(int data)
{
    struct node *ptr, *p;
    p = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->prev_862 = NULL;
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->prev_862 = p;
    }
}

void display()
{
    struct node *ptr, *p;
    ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr = p;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev_862;
    }
}
int main()
{
    addnodefirst(head);
    addnodelast(head);
    display(head);
    return 0;
}