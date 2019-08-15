#include <stdio.h>
#include <stdlib.h>
void selection_sort(int * arr,int n)
{
    while(n>0)
    {
    	int max=-99999,j=0,index=0;
    	for(j=0;j<n;j++)
    	{
    		if(arr[j]>max)
    		{
    		 max=arr[j];
    		 index=j;
    		}
    	}
    	int temp=arr[n-1];
    	arr[n-1]=max;
    	arr[index]=temp;
    	n--;
    }
}
int main()
{
	int size;
	scanf("%d",&size);
	int *arr=(int *)malloc(size*sizeof(int));
	int i=0;
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,size);
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
}
