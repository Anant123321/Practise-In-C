#include <stdio.h>
#include <stdlib.h>
int main()
{
   int n,m,*arr,*brr,i,j;
   scanf("%d",&n);
   arr=(int*)malloc(n*sizeof(int)); //array should be sorted
   scanf("%d",&m);
   brr=(int*)malloc(m*sizeof(int)); //array should be sorted
   for(i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
   for(i=0;i<m;i++)
   {
       scanf("%d",&brr[i]);
   }
   i=0,j=0;
   while(i<n)
    {
      if(arr[i]<brr[j])i++;
      else
      {
        if(arr[i]==brr[j])
        {
          printf("%d",arr[i]);
          i++;j++;
        }
        else
        {
          if(arr[i]>brr[j])j++;
        }
      }
    }
    return 0;
}