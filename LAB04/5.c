#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
int main(){
    struct node *head1,*head2,*head3;
    head1=(struct node *) malloc(sizeof(struct node));
    head2=(struct node *) malloc(sizeof(struct node));
    head3=(struct node *) malloc(sizeof(struct node));
    printf("Enter the info:");
    scanf("%d",&head1->info);
    printf("Enter the info:");
    scanf("%d",&head2->info);
    printf("Enter the info:");
    scanf("%d",&head3->info);
    printf("The info is:%d\n",head1->info);
    printf("The info is:%d\n",head2->info);
    printf("The info is:%d\n",head3->info);
return 0;
}