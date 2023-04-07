// WAP to store n employees data such as employee name, gender, designation,
// department, basic pay etc using structures with dynamically memory allocation.
// Calculate the gross pay of each employees as follows:
// Gross pay=basic pay + HR + DA
// HR=25% of basic, DA=75% of basic
#include<stdio.h>
#include<windows.h>
struct company {
    int id;
    char name[100];
    int age;
    char designation[100];
    char department[100];
    float basic_salary;
    float gross_salary;
};
COORD crd;
void gotoxy(int x, int y)
{
    crd.X = x;
    crd.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
}
void calculate_grosssalary(struct company *ptr,int n){
    for(int i=0;i<n;i++){
        float da,hra;
        da=0.75*((ptr+i)->basic_salary);
        hra=0.25*((ptr+i)->basic_salary);
        (ptr+i)->gross_salary=da+hra+(ptr+i)->basic_salary;
    }
}
void PrintTabularForm(struct company *ptr,int n)
{
    system("cls");
    for (int i = 0; i < n; i++){
        gotoxy(4,2);
        printf("NAME");
        gotoxy(20,2);
        printf("ID");
        gotoxy(35,2);
        printf("AGE");
        gotoxy(50,2);
        printf("DESIGNATION");
        gotoxy(75,2);
        printf("DEPARTMENT");
        gotoxy(96,2);
        printf("BASIC_SALARY");
        gotoxy(118,2);
        printf("GROSS_SALARY");
        gotoxy(4, (i + 3));
        fputs((ptr+i)->name,stdout);
        gotoxy(20, (i + 3));
        printf("%d",(ptr+i)->id);
        gotoxy(35, (i + 3));
        printf("%d",(ptr+i)->age);
        gotoxy(50, (i + 3));
        fputs((ptr+i)->designation,stdout);
        gotoxy(75, (i + 3));
        fputs((ptr+i)->department,stdout);
        gotoxy(96, (i + 3));
        printf("%.3f",(ptr+i)->basic_salary);
        gotoxy(118, (i + 3));
        printf("%.3f",(ptr+i)->gross_salary);
      }
}


int main(){
    int n;
    printf("Enter the number of employee:");
    scanf("%d",&n);
    struct company *ptr;
    ptr=(struct company*) calloc(n,sizeof(struct company));
    // getting details
    for(int i=0;i<n;i++){
        fflush(stdin);
        printf("-----------------------------------------------------\n");
        printf("Enter the name of employee %d:\n",i+1);
        fgets((ptr+i)->name,100,stdin);
        printf("Enter the id of the employee %d:\n",i+1);
        scanf("%d",&(ptr+i)->id);
        printf("Enter the age of the employee %d:\n",i+1);
        scanf("%d",&(ptr+i)->age);
        fflush(stdin);
        printf("Enter the designation of employee %d:\n",i+1);
        fgets((ptr+i)->designation,100,stdin);
        fflush(stdin);
        printf("Enter the department of the employee %d:\n",i+1);
        fgets((ptr+i)->department,100,stdin);
        printf("Enter the basic salary of the employee %d:\n",i+1);
        scanf("%f",&(ptr+i)->basic_salary);
    }
    calculate_grosssalary(ptr,n);
    PrintTabularForm(ptr,n);
return 0;
}