#include<stdio.h>
#include<stdlib.h>
struct STUD
{
    int marks[5];
    int roll_num;
    char name[50];
    char address[100];
};
void enter_data(struct STUD *a,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("\nenter the name of the student number %d : ",i+1);
        scanf(" %[^\n]%*c",(a+i)->name);
        printf("\nenter the address of the student number %d : ",i+1);
        scanf(" %[^\n]%*c",(a+i)->address);
        printf("\nenter the roll number of the student number %d : ",i+1);
        scanf("%d",(a+i)->roll_num);
        printf("enter the marks for student number %d",i+1);
        for(j=0;j<5;j++)
        {
            printf("\nsubject %d : ",j+1);
            scanf("%d",(a+i)->marks[j]);
        }
    }
}
void average(struct STUD *a,int n)
{
    int i,j,sum;
    float avg;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<5;j++)
        {
            sum=sum+a[i].marks[j];
        }
        avg=sum/5.0;
        printf("\naverage for student %d = %0.2f",i+1,avg);
    }
}
void max_marks(struct STUD *a,int n)
{
    int i,j;
    float max;
    for(i=0;i<n;i++)
    {
        max=0;
        for(j=0;j<5;j++)
        {
            if(max<a[i].marks[j])
            max=a[i].marks[j];
        }
        printf("\nmaximum mark for student %d = %0.2f",i+1,max);
    }
}
void min_marks(struct STUD *a,int n)
{
    int i,j;
    float min;
    for(i=0;i<n;i++)
    {
        min=0;
        for(j=0;j<5;j++)
        {
            if(min>a[i].marks[j])
            min=a[i].marks[j];
        }
        printf("\nminimum mark for student %d = %0.2f",i+1,min);
    }
}
int main()
{
    int n;
    printf("enter number of student : ");
    scanf("%d",&n);
    struct STUD *a;
    a=(struct STUD *)malloc(n*sizeof(struct STUD));
    enter_data(a,n);
    average(a,n);
    max_marks(a,n);
    min_marks(a,n);
    return 0;
}