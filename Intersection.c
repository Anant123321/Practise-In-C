
#include <stdio.h>
#include <stdlib.h>
struct range
{
    int upper;
    int lower;
};
int f1(const void* obj1,const void* obj2)
{
    struct range*p1=(struct range*)obj1;
    struct range*p2=(struct range*)obj2;
    return p1->lower - p2->lower;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    struct range *ptr;
    ptr=(struct range*) malloc(n*sizeof(struct range));
    for(i=0;i<n;i++)
    {
       scanf("%d %d",&(ptr+i)->lower,&(ptr+i)->upper);
    }
    qsort(ptr,n,sizeof(struct range),f1);
    struct range *res;
    int size=1;
    res=(struct range*) malloc(size*sizeof(struct range));
    res=ptr;
    int j=0;
    for(i=1;i<n;i++)
    {
        if((res+j)->upper>(ptr+i)->lower)
        {
            (res+j)->upper= (res+j)->upper>(ptr+i)->upper ? (res+j)->upper : (ptr+i)->upper;
        }
        else
        {
            size++;
            j++;
            res=realloc(res,size);
            (res+j)->upper=(ptr+i)->upper;
            (res+j)->lower=(ptr+i)->lower;
        }
    }
    for(i=0;i<size;i++)
    {
        printf("(%d,%d)",(res+i)->upper,(res+i)->lower);
    }
    
}
