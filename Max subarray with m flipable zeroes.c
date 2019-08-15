#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,size,*arr,m,max=0;
    int left=0,right=0,l=0,r=0;
    scanf("%d",&size);
    arr=(int*)malloc(size*sizeof(int));
    for(i=0;i<size;i++)scanf("%d",&arr[i]);
    scanf("%d",&m);
    int num=m;
    while(r<size)
    {
        if(arr[r]==1)r++;
        else
        {
            if(arr[r]==0 && num)
            {
                r++;
                num--;
            }
            else
            {
                while(arr[l]!=0)l++;
                l++;
                if(num<m)num++;
            }            
        }
        if(left>right)right=left;
        if(r<l)r=l;
        if(r-l>max)
            {
                max=r-l;
                right=r;
                left=l;
            }
        
        
    }
    for(i=left;i<right;i++)
    printf("%d",arr[i]);
}

	
