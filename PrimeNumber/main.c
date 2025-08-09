#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num,count=0;
    printf("Enter the number: ");
    scanf("%d",&num);

    for(int i=2; i<num; i++)
    {
        if(num%i==0)
        {
           count++;
           printf("Divided by %d ",i);
           printf("\n");
           break;
        }
    }

    if(count!=0)
    {
        printf("Not Prime");
    }
    else
    {
        printf("Prime");
    }
    return 0;
}
