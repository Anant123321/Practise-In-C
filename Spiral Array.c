
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i=0,j=0;
    scanf("%d",&n);
    int **arr;
    arr=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(n*sizeof(int));
    }
    int start=0,end=0;
    while(end<n/2)
    {
        start=end;
        for(i=end;i<n-end;i++)
        {
            scanf("%d",&arr[start][i]);
        }
        i--;
        for(start=start+1;start<n-end;start++)
        { 
            scanf("%d",&arr[start][i]);
        }
        start--;
        for(i=i-1;i>=0+end;i--)
        {
            scanf("%d",&arr[start][i]);
        }
        i++;
        for(start=start-1;start>0+end;start--)
        {
            scanf("%d",&arr[start][i]);
        }
        end++;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n",arr[i][j]);
    }
    return 0;
}
