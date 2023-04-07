#include <stdio.h>
#include <string.h>
void swap(char *x,char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permutations(char *a, int i,int len)
{
    if(i==len)
    {
    printf("%s\n",a);
    return ;
    }
    else
    {
        for(int j=i;j<len;j++)
        {
        swap((a+i),(a+j));
        permutations(a,i+1,len);
        swap((a+i),(a+j));
        }
    }
}
int main()
{
    char a[50];
    int  len;
    printf("enter a word\n");
    scanf("%s", a);
    len = strlen(a);
    printf("\npermutations of %s are\n",a);
    permutations(a,0,len);
    return 0;
}