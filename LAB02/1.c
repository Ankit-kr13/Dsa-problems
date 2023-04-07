#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the number of elements in array:\n");
    scanf("%d",&n);
    int *arr,*brr;
    arr=(int*) calloc(n,sizeof(int));
    brr=(int*) calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",(arr+i));
    }
    *brr=(*(arr))*(*(arr+1));
    *(brr+n-1)=(*(arr+n-1))*(*(arr+n-2));
    for(int j=1;j<n-1;j++){
        *(brr+j)=(*(arr+j-1))*(*(arr+j+1));
    }
    printf("---------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("%d\n",*(brr+i));
    }
    printf("-------------------------------------------------\n");
return 0;
}