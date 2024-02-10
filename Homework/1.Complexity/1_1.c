#include <stdio.h>
#include <stdlib.h>

int main()
{
    int K=0;
    scanf("%d",&K);
    int* a=(int*)malloc(sizeof(int)*K);
    int cnt=0;
    int number;
    while(cnt<K)
    {
        scanf("%d",&number);
        a[cnt++]=number;
    }
    int i=0;
    int MaxSum=0;
    int ThisSum=0;
    for(i=0;i<K;i++)
    {
        ThisSum += a[i];
        if(ThisSum>MaxSum)
        {
            MaxSum=ThisSum;
        }
        else if(ThisSum<0)
        {
            ThisSum=0;
        }
    }
    printf("%d\n",MaxSum);
    return 0;
}
