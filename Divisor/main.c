#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,count=0;
    printf("Enter the number: ");
    scanf("%d",&num);

    for(int i=1; i<=num; i++)
    {
        if(num%i==0)
        {
            count++;
            printf("%d ",i);
        }
    }
    printf("\n");
    printf("Output: %d",count);
    return 0;
}
