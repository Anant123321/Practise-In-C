#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
	int data;
	struct node* next;
}node;

void create_list(node ** head,int n)
{
    node * current = (*head);
    int i=0;
    for(i=0;i<n;i++)
    {
   	  node * newnode=(node*)malloc(sizeof(node));
   	  newnode->next = NULL;
   	  scanf("%d",&newnode->data);
   	  if(i==0)
   	  {
   	  	(*head)=newnode;
   	  	current=newnode;
   	  }
   	  else
   	  {
   	  	current->next=newnode;
   	  	current=newnode;
   	  }
   }
   //making the list cyclic..i.e. last node points to any other node
   current->next=(*head)->next;
}

int check(node * head)
{
	int key=0;
	node * slow = head;
	node * fast = head;
	do
	{
	   if(fast->next==NULL)break;
	   fast=fast->next;
	   if(fast->next==NULL)break;
	   fast=fast->next;
	   slow=slow->next;
	   if(slow==fast)
	   {
	   	key=1;
	   	break;
	   }
	}while(fast!=slow && fast->next!=NULL && slow->next!=NULL);
	return key;
}
int main()
{
	int i=0,n=0;
	scanf("%d",&n);
	node * head = NULL;
    create_list(&head,n);
    int res = check(head);
    res == 1 ? printf("True") : printf("False") ;
}