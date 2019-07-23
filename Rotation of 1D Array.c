#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,*arr,i,j;
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)scanf("%d",&arr[i]);
    int rotations;
    scanf("%d",&rotations);
   for(i=0;i<rotations%n;i++)
    {
        int temp=*(arr+n-1);
    	for(j=n-1;j>0;j--)
    	{
           *(arr+j)=*(arr+j-1);
    	}
    	*arr=temp;
    }
    for(i=0;i<n;i++)printf("%d ",*(arr+i));
}