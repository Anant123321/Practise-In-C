#include<stdio.h>
#include<stdlib.h>
int main()
{
   int n,i,j;
   scanf("%d",&n);
   int **arr=(int**)malloc(n*sizeof(int*));
   for(i=0;i<n;i++)
   {
   	 arr[i]=(int*)malloc(n*sizeof(int));
   }
   for(i=0;i<n;i++)
   	for(j=0;j<n;j++)
   		scanf("%d",&arr[i][j]);
   	int r=1,c=1;
   	for(i=0;i<n;i++)
   	{
   		if(arr[0][i]==0)
   		{
   		    r=0;
   		    break;
   		}
   	}
   	for(i=0;i<n;i++)
   	{
   		if(arr[i][0]==0)
   		{
   		    c=0;
   		    break;
   		}
   	}
   	for(i=1;i<n;i++)
   	{
   		for(j=1;j<n;j++)
   		{
   		   if(arr[i][j]==0)
   		   {
   		   	 arr[0][j]=0;
   		   	 arr[i][0]=0;
   		   } 
   		}
   	}
    for(i=1;i<n;i++)
    {
    	if(arr[0][i]==0)
    		for(j=1;j<n;j++)
    		{
    			arr[j][i]=0;
    		}
    }
    for(j=1;j<n;j++)
    {
    	if(arr[j][0]==0)
    		for(i=1;i<n;i++)
    		{
    			arr[j][i]=0;
    		}
    }
    if(r==0)
    	for(i=0;i<n;i++)arr[0][i]=0;
    if(c==0)
    	for(j=0;j<n;j++)arr[j][0]=0;
    	printf("\n");
   	for(i=0;i<n;i++)
   	{
   	    for(j=0;j<n;j++)
   	    {
   		   printf("%d ",arr[i][j]);
   	    }
   	    printf("\n");
   	}
}