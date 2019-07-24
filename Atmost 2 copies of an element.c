#include <stdio.h>
#include <stdlib.h>
int main()
{
   int j=0,n,*arr,i;
   scanf("%d",&n);
   arr=(int*)malloc(n*sizeof(int)); //array should be sorted
   for(i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
   for(i=0;i<n-2;i++)
   {
   	 if(arr[i+1]==arr[i] && arr[i+2]==arr[i]){}
   	 else	
   	 {
   	 	arr[j]=arr[i];
   	 	j++;
   	 }
   }
   for(i;i<n;i++)
   {
   	arr[j]=arr[i];
   	j++;
   }
   for(i=0;i<j;i++)
   {
       printf("%d",arr[i]);
   }
    return 0;
}