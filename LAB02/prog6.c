// Given array of integer, find the next smaller of next greater element of every element in
// array. Elements for which no greater element exists or no smaller of greater element exist,
// print -1.
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of element in an array:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the element %d :",i+1);
        scanf("%d",&arr[i]);
    }
    int nge,nse,index;
    printf("Next Greater\tRight Smaller\n");
    for(int i=0;i<n;i++){
        nge=nse=-1;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                index=j;
                nge=arr[j];
                break;
            }  
        }
        for(int j=i+1;j<n;j++){
            for(int z=index+1;z<n;z++){
                    if(nge>arr[z]){
                        nse=arr[z];
                        break;
                    }
                } 
        }

        printf("%d-->%d\t\t%d-->%d\n",arr[i],nge,nge,nse);
        // printf("%d-->%d\n",nge,nse);
        
    }
return 0;
}