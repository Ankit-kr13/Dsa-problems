#include<stdio.h>
#include<stdlib.h>
struct node{
    int roll;
    char name[50];
    int age;
    float cgpa;
    struct node *link;
};
int main(){
    struct node *head1;
    head1=(struct node *) malloc(sizeof(struct node));
    printf("Enter the roll:\n");
    scanf("%d",&head1->roll);
    fflush(stdin);
    printf("Enter the name:\n");
    fgets(head1->name,50,stdin);
    printf("Enter the age:\n");
    scanf("%d",&head1->age);
    printf("Enter the cgpa:\n");
    scanf("%f",&head1->cgpa);
    head1->link=NULL;
    printf("The roll no of the student is:%d\n",head1->roll);
    printf("The name of the student is:");
    fputs(head1->name,stdout);
    printf("The age of the student is:%d\n",head1->age);
    printf("The cgpa of the student is:%f\n",head1->cgpa);
    

    
return 0;
}