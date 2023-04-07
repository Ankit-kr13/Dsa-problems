// WAP to swap all the elements in the 1st column with all the corresponding elements in the
// last column, and 2nd column with the second last column and 3rd with 3rd last etc. of a 2-D
// array. Display the matrix.
#include<stdio.h>

int main(){
    int rows,columns;
    printf("Enter the number of rows in an array:\n");
    scanf("%d",&rows);
    printf("Enter the number of columns in an array:\n");
    scanf("%d",&columns);
    int arr[rows][columns];
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Enter the element arr[%d][%d] :",i,j);
            scanf("%d",&arr[i][j]);
        }    
    }
    printf("Before Swapping:\n\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d\t",arr[i][j]);
        }  
        printf("\n");  
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns/2;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[i][columns-j-1];
            arr[i][columns-j-1]=temp;
        }    
    }
    printf("After Swapping:\n\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d\t",arr[i][j]);
        }  
        printf("\n");  
    }

return 0;
}