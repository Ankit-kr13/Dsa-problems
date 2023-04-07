// WAP to search an element in an array of n numbers.

#include <stdio.h>
 
int main() {
   int num, i, r, arr[30];
 
   printf("Enter the number of elements in the array: ");
   scanf("%d", &num);
 
   printf("Enter the array elements: ");
   for (i = 0; i < num; i++) {
      scanf("%d", &arr[i]);
   }
 
   printf("Enter the item to be searched: ");
   scanf("%d", &r);
 
   
   i = 0;
   while (i < num && r != arr[i]) {
      i++;
   }
 
   if (i < num) {
      printf("The element is found in the position = %d", i + 1);
   } else {
      printf("Element not found!");
   }
 
   return 0;
}