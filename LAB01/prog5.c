/* Given an unsorted array of size n, WAP to find number of elements between two elements a and b
(both inclusive).
Input : arr = [1, 2, 2, 7, 5, 4]
a=2 b=5
Output : 4
(The numbers are: 2, 2, 5, 4)
If a=6 b=15, then output will be 3 */
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of element in an array:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the element %d :\n",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int a,b,j,m;
    printf("Enter the initial range:\n");
    scanf("%d",&a);
    printf("Enter the final range:\n");
    scanf("%d",&b);
    int count;
    for(int i=0;i<n;i++){
        if(arr[i]==a){
            j=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]==b){
            m=i;
        }

    }
    count=m-j+1;
    printf("The number of element between %d and %d:%d",a,b,count);
    
return 0;
}