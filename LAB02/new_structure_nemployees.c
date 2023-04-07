#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct employees
{
    char gender;
    char department[50],designation[50];
    float basic_salary,gross_salary;
    char name[100];
};
void enter_data(struct employees *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter name of employee number %d : ", i + 1);
        scanf(" %[^\n]%*c", a[i].name);
        printf("\nenter gender(M/F) of the employee number %d : ", i + 1);
        scanf(" %c", &a[i].gender);
        printf("\nenter department of the employee number %d : ", i + 1);
        scanf(" %[^\n]%*c", a[i].department);
        printf("\nenter designation of the employee number %d : ", i + 1);
        scanf(" %[^\n]%*c", a[i].designation);
        printf("\nenter basic salary for employee number %d\n", i + 1);
        scanf("%f", &a[i].basic_salary);
    }
}
void grosssalary(struct employees *a, int n)
{
    int i;
    float DA,HRA;
    for (i = 0; i < n; i++)
    {
        DA=0.75*(a[i].basic_salary);
        HRA=0.25*(a[i].basic_salary);
        a[i].gross_salary=a[i].basic_salary+DA+HRA;
    }
}
void display(struct employees *a, int n)
{
    int i;
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("\nname of employee number %d : %s", i + 1,a[i].name);
        printf("\ngender of the employee number %d : %c", i + 1,a[i].gender);
        printf("\ndesignation of the employee number %d : %s", i + 1,a[i].designation);
        printf("\ndepartment of the employee number %d : %s", i + 1,a[i].department);
        printf("\nbasic salary for employee number %d : %f", i + 1,a[i].basic_salary);
        printf("\ngross salary for employee number %d : %f", i + 1,a[i].gross_salary);
    }
}
int main()
{
    int i, n;
    printf("enter number of the employees : ");
    scanf("%d", &n);
    struct employees *a;
    a = (struct employees *)malloc(n * sizeof(struct employees));
    enter_data(a,n);
    grosssalary(a,n);
    display(a,n);
    free(a);
    return 0;
}