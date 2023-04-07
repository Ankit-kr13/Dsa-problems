/** Write a program to declare a structure DATE containing day, month and year. Find
the age of a person if the date of birth and current date is given. */
#include <stdio.h>
#include <math.h>
struct DATE
{
      int date,month;
      int yr;
      int Cdate, Cmonth, Cyr;
      int age;
};
int calculate(int yr,int currentYr)
{
      int age;
      age=abs(yr-currentYr);
      return age;
}
int main()
{
      struct DATE details;
      printf("Enter Date of Birth: \n");
      printf("Enter date component: ");
      scanf("%d", &details.date);
      printf("Enter month component: ");
      scanf("%d", &details.month);
      printf("Enter year component: ");
      scanf("%d", &details.yr);
      printf("Date of birth entered by user is: %d/%d/%d ", details.date, details.month, details.yr);
      printf("\n\nEnter current date: \n");
      printf("Enter date component: ");
      scanf("%d", &details.Cdate);
      printf("Enter month component: ");
      scanf("%d", &details.Cmonth);
      printf("Enter year component: ");
      scanf("%d", &details.Cyr);
      printf("The current date given by user is: %d/%d/%d ", details.Cdate, details.Cmonth, details.Cyr);
      printf("\n\nThe age of the person is: %d",calculate(details.yr,details.Cyr));
}