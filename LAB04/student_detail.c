#include <stdio.h>
#include <stdlib.h>
struct node
{
    int roll_num, age;
    char name[100];
    float cgpa;
    struct node *next;
};
struct node *head;
int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    printf("\nenter name of student  : ");
    scanf(" %[^\n]%*c",head->name);
    printf("\nenter roll number of student  : ");
    scanf("%d", &head->roll_num);
    printf("\nenter age of the student  : ");
    scanf("%d", &head->age);
    printf("\nenter cgpa of student  : ");
    scanf("%f", &head->cgpa);
    printf("\nfollowing are the detail of the student\n");
    printf("\nname of student : %s\n",head->name);
    printf("\nroll number of student : %d\n",head->roll_num);
    printf("\ncgpa of student : %0.2f \n",head->cgpa);
    printf("\nage of the student : %d\n",head->age);
    return 0;
}
