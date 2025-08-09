#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,first=0,second=1,temp=0;
    printf("Enter the number: ");
    scanf("%d",&num);

    for(int i=0; i<=num; i++)
    {
        printf("%d  ",first);
        temp = first + second;
        first = second;
        second = temp;
    }
    return 0;
}
