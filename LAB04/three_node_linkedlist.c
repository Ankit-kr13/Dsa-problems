#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *ptr)
{
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    struct node *head,*first,*second,*third;
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    printf("\nenter data in first node : ");
    scanf("%d",&first->data);
    printf("\nenter data in first node : ");
    scanf("%d",&second->data);
    printf("\nenter data in first node : ");
    scanf("%d",&third->data);
    head=first;
    first->next=second;
    second->next=third;
    third->next=NULL;
    display(head);
    return 0;
}