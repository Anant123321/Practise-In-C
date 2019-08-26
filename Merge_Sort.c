#include <stdio.h>
#include <stdlib.h>

void merge(int * a,int n,int l,int r)
{
    int mid=(l+r)/2;
    int i=l,j=mid+1,k=l;
    int temp[n];
    while(i<=mid && j<=r)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=r)
    {
        temp[k++]=a[j++];
    }
    for(i=l;i<=r;i++)
    {
        a[i]=temp[i];
    }
}

void merge_sort(int * arr,int n,int l,int r)
{
    if (l>=r) return;
    int mid=(l+r)/2;
    merge_sort(arr,n,l,mid);
    merge_sort(arr,n,mid+1,r);
    merge(arr,n,l,r);
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
    merge_sort(arr,size,0,size-1);
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
