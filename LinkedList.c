#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;

}node;

node * delete(int pos,node* head)
{
    int i=1;
    node * current=head;
    node * temp;
    if(pos<=0)
    {
        printf("Invalid Position\n");
        return head;
    }
    if(pos==1)
    {
        head=current->next;
    }
    else
    {
        while(i<pos-1 && current->next!=NULL)
        {
            current=current->next;
            i++;
        }
        if(current->next==NULL)printf("Invalid Input\n");
        else
        current->next=(current->next)->next;
    }
    return head;
}

void print(node *head)
{
   printf("\nValues After Last operation are:-\n");
   node * current=head;
  while(current->next != NULL)
   {
       printf("%d ",current->data);
       current=current->next;
   }
    printf("%d\n",current->data);
}

node * insert(int pos,int value,node * head)
{
    int i=1;
    node * current=head;
    node * newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    if(pos<=0)
    {
        printf("Invalid Position\n");
        return head;
    }
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        while(i<pos-1 && current->next!=NULL)
        {
            i++;
            current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;
    }
    return head;
}

node * create(int n)
{
   printf("\nEnter The Values:-\n");
   node *head=NULL;
   int i=0;
   for(i=0;i<n;i++)
   {
   	node * newnode=(node*)malloc(sizeof(node));
   	node * current;
   	scanf("%d",&newnode->data);
   	newnode->next=NULL;
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
int main()
{
    node *head=NULL;
    int n,value;
    printf("Input No. Of Nodes to initialise the List:-\n");
    scanf("%d",&n);
	head=create(n);
	print(head);
	printf("\nInput the node to delete\n");
	scanf("%d",&n);
	head=delete(n,head);
	print(head);
	printf("\nInput the position and value to insert\n");
	scanf("%d %d",&n,&value);
	head=insert(n,value,head);
	print(head);
}