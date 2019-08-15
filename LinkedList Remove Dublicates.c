/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}node;

void print(node * head)
{
    node * current=head;
    if(head==NULL)printf("Empty List");
    else
    {
        while(current->next!= NULL)
        {
            printf("%d ",current->data);
            current=current->next;
        }
        printf("%d\n",current->data);
    }
}
node * create(int n)
{
    node * head=NULL;
    int i=0;
    int value=0;
    node * current;
    for(i=0;i<n;i++)
    {
        node * newnode=(node *)malloc(sizeof(node));
        newnode->next=NULL;
        scanf("%d",&value);
        newnode->data=value;
        if(i==0)
        {
            head=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;
            
        }
    }
    return head;
}
node * remove1(node * head) // remove dublicates... 1 1 2 2 3 3 becomes 1 2 3
{
    node * current=head;
    while(current->next!=NULL)
    {
        if(current->data==current->next->data)
        {
            current->next=(current->next)->next;
        }
        else
        {
            current=current->next;
        }
    }
    return head;
}
node *remove2(node * head) // remove all the occurances of repeating nos. eg 0 1 1 2 2 3 becomes 0 3.
{
    node* dummy=(node *)malloc(sizeof(node));
    dummy->next=head;
    head=dummy;
    int key=0,temp=0;
    node * ptr1,*ptr2,*current;
    current=dummy;
    ptr1=dummy->next;
    ptr2=ptr1->next;
   // printf("Value=%d %d %d %d\n",current->next->data,dummy->next->data,ptr1->data,ptr2->data);
    while(ptr1->next->next!=NULL)
    {
        if(ptr1->data==ptr2->data)
        {
            temp=ptr2->data;
            ptr2=ptr2->next;
            ptr1=ptr1->next;
           
            key=1;
        }
        else
        {
            if(key==0)
            {
                current->next=ptr1;
                current=ptr1;
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            else
            {
                current->next=ptr2;
                ptr1=ptr2;
                ptr2=ptr2->next;
                key=0;
            }
        }
        
    }
    if(ptr1->data==ptr2->data)current->next=NULL;
    else
    {
        current->next=ptr1;
        current->next->next=ptr2;
    }
    head=dummy->next;
    return head;
}
int main()
{
    int n;
    node * head=NULL;
    scanf("%d",&n);
    head=create(n);
    print(head);
    head=remove2(head);
    print(head);
    return 0;
}
