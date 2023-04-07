#include <stdio.h>
#include <string.h>
int length(char *a)
{
    int i = -1;
    while (a[++i])
        ;
    return i;
}
void concatenate(char *word, char *new_string)
{
    int len, i, j = 0;
    len = length(new_string);
    if (len == 0)
    {
        for (i = len; word[j]; i++)
        {
            new_string[i] = word[j];
            j++;
        }
        new_string[i] = '\0';
        return;
    }
    new_string[len] = ' ';
    for (i = (len + 1); word[j]; i++)
    {
        new_string[i] = word[j];
        j++;
    }
    new_string[i] = '\0';
}
void substring(char *string, char *word, int start, int end)
{
    int i, j = 0;
    for (i = start + 1; i < end; i++)
    {
        word[j] = string[i];
        j++;
    }
    word[j] = '\0';
}
int main()
{
    char string[100], word[100], new_string[100]="\0";
    int i, j, len;
    printf("enter a string\n");
    gets(string);
    len = length(string);
    for (i = len; i >= 0; i--)
    {
        string[i + 1] = string[i];
    }
    string[0] = ' ';
    len = length(string);
    j = len;
    for (i = len - 1; i >= 0; i--)
    {
        if (string[i] == ' ')
        {
            substring(string, word, i, j);
            j = i;
            concatenate(word, new_string);
        }
    }
    printf("%s", new_string);
    return 0;
}