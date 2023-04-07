#include<stdio.h>
#include<string.h>

int main()
{
    struct employee
    {
        char name[100];
        int age;
        float salary;
    };
    struct employee e1,e2,e3;
    printf("\n enter \n1. name\n2. age \n3. salary\n for a employee\n");
    scanf("%s",e1.name);
    scanf("%d",&e1.age);
    scanf("%f",&e1.salary);
    strcpy(e2.name,e1.name);
    e2.age=e1.age;
    e2.salary=e1.salary;
    printf("\npiece-meal copying : \n");
    printf("1.name  \t%s\n2. age   \t%d\n3. salary\t%f\n\n",e2.name,e2.age,e2.salary);
    e3=e1;
    printf("\n copying all elements at one go :\n");
    printf("1.name  \t%s\n2. age   \t%d\n3. salary\t%f\n\n",e3.name,e3.age,e3.salary);
    return 0;
}