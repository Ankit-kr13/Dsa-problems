#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void createsingle()
{
    int n;
    printf("enter size of single linkedlist : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct node *ptr, *p;
        p = head;
        ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == NULL)
        {
            printf("can't add the node");
            exit;
        }
        printf("\nenter a number : ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = ptr;
        }
    }
}
void displaysingle()
{
    struct node *ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void displayalternatesingle()
{
    struct node *ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next->next;
    }
}
int main()
{
    createsingle();
    printf("the following list is\n");
    displaysingle();
    printf("\nthe alternate data of following list is\n");
    displayalternatesingle();
    return 0;
}