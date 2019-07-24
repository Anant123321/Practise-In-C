
#include <stdio.h>
#include <stdlib.h>
int max_ele(int *arr,int size,int key)
{
    int max=-99999;
    int i=0,index=0;
    for(i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            index=i;
        }
    }
    if(key==0)
        return max;
    else
        return index;
}
int main()
{
    int n,i=0,j=0;
    scanf("%d",&n);
    int *up,*down;
    up=(int*)malloc(n*sizeof(int));
    down=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&up[i]);
        scanf("%d",&down[i]);
    }
    int size=max_ele(down,n,0);
    int *arr=(int*)malloc((size+2)*sizeof(int));
    for(i=0;i<n;i++)
    {
         arr[up[i]]++;
         arr[down[i]+1]--; 
    }
    int prev=0;
    for(i=0;i<size+2;i++)
    {
        *(arr+i)=*(arr+i)+prev;
         prev=*(arr+i);
    }
    printf("%d",max_ele(arr,size,1));
    
return 0;    
}