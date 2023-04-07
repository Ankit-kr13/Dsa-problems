#include<stdio.h>
int length(char *a)
{
    int i=-1;
    while(*(a+(++i)));
    return i;
}
int main()
{
    char a[100];
    printf("enter a string : ");
    scanf("%s",a);
    printf("length of %s is %d",a,length(a));
    return 0;
}