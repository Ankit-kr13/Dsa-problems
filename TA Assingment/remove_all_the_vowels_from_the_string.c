#include <stdio.h>
#include <string.h>
void delete (char *a, int position)
{
    int k;
    for (k = position; a[k]; k++)
    {
        a[k] = a[k + 1];
    }
}
void display(char *a)
{
    printf("\n");
    printf("%s\n", a);
}
int main()
{
    int n, i, j;
    char a[100];
    printf("enter a string : ");
    gets(a);
    for (i = 0; a[i]; i++)
    {
        if ((a[i] == 'a') || (a[i] == 'e') || (a[i] == 'i') || (a[i] == 'o') || (a[i] == 'u') || (a[i] == 'A') || (a[i] == 'E') || (a[i] == 'I') || (a[i] == 'O') || (a[i] == 'U'))
        {
            delete (a, i);
            i--;
        }
    }
    display(a);
    return 0;
}