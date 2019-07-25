#include<stdio.h>
#include<stdlib.h>
int max_ele(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : ( b > c ? b : c );
}

int min_ele(int a, int b, int c)
{
	return a < b ? (a < c ? a : c) : ( b < c ? b : c );
}
int main()
{
	int s1,s2,s3,i,j=0,k=0,res=99999;
	scanf("%d %d %d",&s1,&s2,&s3);
	int *arr,*brr,*crr;
	arr=(int*)malloc(s1*sizeof(int));
	brr=(int*)malloc(s2*sizeof(int));
	crr=(int*)malloc(s3*sizeof(int));
	for(i=0;i<s1;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<s2;i++)
		scanf("%d",&brr[i]);
	for(i=0;i<s3;i++)
		scanf("%d",&crr[i]);
	i=0;
    while(i<s1 && j<s2 && k<s3)
    {
       int max=max_ele(arr[i],brr[j],crr[k]);
       int min=min_ele(arr[i],brr[j],crr[k]);
       if((max-min)<res)res=max-min;
       printf("%d %d %d\n",max,min,res);
       if(min==arr[i])i++;
       if(min==brr[j])j++;
       if(min==crr[k])k++; 
    }
    printf("%d",res);
}
