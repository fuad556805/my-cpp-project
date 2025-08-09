#include<stdio.h>
int main()
{
    int num,first=0,second=0,temp=0;
    printf("Enter the number: ");
    scanf("%d",&num);

    for(int i=0; i<=num; i++)
    {
        printf("%d",first);
        first = 0;
        second = first;
        first = temp;
    }
    return 0;
}
