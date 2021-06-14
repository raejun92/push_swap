#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = malloc(sizeof(int) * 3);
    *(a + 0) = 13;
    *(a + 1) = 4;
    *(a + 2) = 57;
    

    int len, i;
    i = 0;
    while (a[i])
        i++;
    if (i % 2 != 0)
        i = i / 2 + 1;
    else
        i = i / 2;
    
    printf("%d\n", i);
    return (0);
}