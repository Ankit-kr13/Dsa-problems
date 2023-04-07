// Let A be n*n square matrix array. WAP by using appropriate user defined functions for the following:
// a) Find the number of nonzero elements in A
// b) Find the sum of the elements above the leading diagonal.
// c) Display the elements below the minor diagonal.
// d) Find the product of the diagonal elements.
#include<stdio.h>
void find_nonzero(int n,int arr[][n]){
    printf("-------------------------------------------------------\n");
    printf("The nonzero elements in multidimensional square matrix are:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                printf("arr[%d][%d]-->%d\n",i,j,arr[i][j]);
            }
        }
    }
    printf("-------------------------------------------------------\n");
}
void sum_aboveleadingdiagonal(int n,int arr[n][n]){
    printf("-------------------------------------------------------\n");
    int sum=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            sum+=arr[i][j];
        }
    }
    printf("The sum of the elements above the leading diagonal is: %d",sum);
    printf("-------------------------------------------------------\n");

}
void display_minorelements(int n,int arr[n][n]){
    printf("-------------------------------------------------------\n");
    printf("The elements below the minor diagonal are:\n");
    for(int i=1;i<n;i++){
        for(int j=n-i;j<n;j++){
            printf("arr[%d][%d]-->%d\n",i,j,arr[i][j]);
        }
    }
    printf("-------------------------------------------------------\n");
}
void product_diagonalelement(int n,int arr[n][n]){
    printf("-------------------------------------------------------\n");
    int major_product=1,minor_product=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                major_product*=arr[i][j];
            }
            if((i+j)==(n-1)){
                minor_product*=arr[i][j];
            }
        }
    }
    printf("The product of elements in leading diagonal is:%d\n",major_product);
    printf("The product of elements in minor diagonal is:%d\n",minor_product);
    printf("-------------------------------------------------------\n");
}
int main(){
    int n,choice;
    printf("-------------------------------------------------------\n");
    printf("Enter the numbers of rows or columns of square matrix:\n");
    scanf("%d",&n);
    int arr[n][n];
    // getting input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter the value of arr[%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("-------------------------------------------------------\n");
    printf("Press 1 to find the number of nonzero elements\n");
    printf("Press 2 to find the sum of the elements above the leading diagonal\n");
    printf("Press 3 to display the elements below the minor diagonal\n");
    printf("Press 4 to find the product of the diagonal elements\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        find_nonzero(n,arr);
        break;
        case 2:
        sum_aboveleadingdiagonal(n,arr);
        break;
        case 3:
        display_minorelements(n,arr);
        break;
        case 4:
        product_diagonalelement(n,arr);
        break;
        default:
        printf("Invalid choice!!");
    }
    // find_nonzero(n,arr);
    // sum_aboveleadingdiagonal(n,arr);
    // display_minorelements(n,arr);
    // product_diagonalelement(n,arr);
return 0;
}