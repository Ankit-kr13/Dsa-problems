// WAP to sort rows of a matrix having m rows and n columns in ascending & columns in
// descendng order.
#include<stdio.h>
void sort_rows_ascending(int rows,int columns,int arr[rows][columns]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns-1;j++){
            for(int z=j+1;z<columns;z++){
                if(arr[i][j]>arr[i][z]){
                    int temp=arr[i][j];
                    arr[i][j]=arr[i][z];
                    arr[i][z]=temp;
                }
            }
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
void sort_columns_descending(int rows,int columns,int arr[rows][columns]){
    for(int j=0;j<columns;j++){
        for(int  i=0;i<rows-1;i++){
            for(int z=i+1;z<rows;z++){
                 if(arr[i][j]<arr[z][j]){
                    int temp=arr[i][j];
                    arr[i][j]=arr[z][j];
                    arr[z][j]=temp;
                }
            }
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    

}

int main(){
    int rows,columns,choice;
    printf("Enter the numbers of rows and columns respectively:\n");
    scanf("%d %d",&rows,&columns);
    int arr[rows][columns];
    // geting input
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Enter the value of arr[%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);

        }
    }
    printf("Press 1 for sorting the rows in ascending order.\n");
    printf("Press 2 for sorting the column in descending order.\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        sort_rows_ascending(rows,columns,arr);
        break;
        case 2:
        sort_columns_descending(rows,columns,arr);
        break;
        default:
        printf("Invalid choice!!");
    }
return 0;
}