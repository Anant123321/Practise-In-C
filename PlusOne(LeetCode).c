#include<stdio.h>
#include<stdlib.h>

int* plusOne(int* digit, int n ,int* returnSize)
{
    int * arr=(int*)malloc((n+1)*sizeof(n));
    int i=0,carry=-1;
    if(digit[n-1]!=9)digit[n-1]++;
    else
    {
        for(i=n-1;i>=0;i--)
        {
            if(digit[i]==9)
            {
                digit[i]=0;
                carry=1;
            }
            else
            {
                digit[i]++;
                carry=0;
                break;
            }
        }
    }
    int key=1,k=0;
    if(carry==1)arr[k++]=1;
    for(i=0;i<n;i++)
    {
        if(digit[i]==0 && key==1 && carry!=1)
        {
          continue;   
        }
        else
        {
            arr[k++]=digit[i];
            key=0;
        }
    }
    *returnSize=k;
    return arr;

}

int main()
{
    int n,i;
    scanf("%d",&n);
    int * num=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&num[i]);
    }
    int size=0;
    int * res=plusOne(num,n,&size);
    for(i=0;i<size;i++)
    {
        printf("%d",res[i]);
    }
}