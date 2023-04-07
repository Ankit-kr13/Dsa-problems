#include <stdio.h>
int main()
{
    int i, count = 0, j, temp, prime = 0, lower_limit, upper_limit;
    printf("enter lower limitt and upper limit of the range\n");
    scanf("%d %d", &lower_limit, &upper_limit);
    for (i = lower_limit; i <= upper_limit; i++)
    {
        count = 0;
        temp = i / 2;
        for (j = 2; j <= temp; j++)
        {
            if (i % j == 0)
            {
                count++;
                break;
            }
        }
        if (count == 0)
        {
            if (prime == 0)
            {
                printf("prime no. between %d to %d are :\n", lower_limit, upper_limit);
            }
            printf("%d  ", i);
            prime++;
        }
    }
    printf("\ntotal number of prime no. between %d to %d are : %d", lower_limit, upper_limit, prime);
    return 0;
}