/* WAP to swap three numbers in cyclic order using Call by Reference. In other words, WAP that takes
three variable (a, b, c) in as separate parameters and rotates the values stored so that value a goes to
b, b to c and c to a. */
#include<stdio.h>
void swap(int *a,int *b,int *c){
    int temp=*a;
    *a=*c;
    *c=*b;
    *b=temp;
}
int main(){
    int num1,num2,num3;
    printf("Enter the num1 num2 num3:\n");
    scanf("%d %d %d",&num1,&num2,&num3);
    swap(&num1,&num2,&num3);
    printf("After swapping:\n");
    printf("%d\t%d\t%d",num1,num2,num3);
return 0;
}