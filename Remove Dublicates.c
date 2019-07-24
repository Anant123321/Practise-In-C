#include <stdio.h>
#include <stdlib.h>
int main()
{
   int j=0,n,*arr,i;
   scanf("%d",&n);
   arr=(int*)malloc(n*sizeof(int));
   for(i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
   for(i=1;i<n;i++)
   {
       if(*(arr+j)!=*(arr+i))
       {
           j++;
           *(arr+j)=*(arr+i);
       }
   }
   for(i=0;i<=j;i++)
   {
       printf("%d",arr[i]);
   }
    return 0;
}