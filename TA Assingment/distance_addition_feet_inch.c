#include<stdio.h>

int main()
{
    int feet_1,feet_2,inch_1,inch_2,feet_final,inch_final;
    printf("enter fisrt distance in feet and inches\n");
    scanf("%d %d",feet_1,inch_1);
    printf("enter second distance in feet and inches\n");
    scanf("%d %d",feet_2,inch_2);
    printf("distance entered are %d feet %d inch and %d feet %d inch",feet_1,inch_1,feet_2,inch_2);
    feet_final=feet_1+feet_2;
    inch_final=inch_1+inch_2;
    while (inch_final>=12)
    {
        inch_final-=12;
        feet_final+=1;
    }
    printf("total distance : %d feet %d inch",feet_final,inch_final);
    return 0;
}