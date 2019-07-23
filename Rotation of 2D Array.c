#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,**arr,i,j;
	scanf("%d",&n);
	arr=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		arr[i]=(int*)malloc(n*sizeof(int));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
    for(i=0;i<n/2;i++)
    {
    	for(j=i;j<n-1-i;j++)
    	{
    		int temp=arr[i][j];
    		arr[i][j]=arr[n-1-j][i];
    		arr[n-1-j][i]=arr[n-1-i][n-1-j];
    		arr[n-1-i][n-1-j]=arr[j][n-1-i];
    		arr[j][n-1-i]=temp;
    	}
    }
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}