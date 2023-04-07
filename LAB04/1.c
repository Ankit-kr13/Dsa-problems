#include<stdio.h>

int main(){

    int arr[100];
    int n;

    printf("Enter the value of N:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
       }

    int c=0;
    for(int i=0;i<n-1;i++){

        for (int j=i+1;j<n;j++){

            if (arr[j-1]<arr[j]){

                c++;
            }
        }
         
    }
    printf("%d",c);
   
    return 0;

}