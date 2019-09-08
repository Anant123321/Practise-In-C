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
  node * slow=head;
  node * fast=head;
  while(slow->next!= NULL && slow!=NULL && fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next;
    if(fast)
    {
      fast=fast->next;
    }
    if(slow==fast)
    {
       slow=head;
       while(slow!=fast)
       {
        slow=slow->next;
        fast=fast->next;
       }
       return slow->data;
    }
  }
  return -1;
}

int main()
{
	int i=0,n=0;
	scanf("%d",&n);
	node * head = NULL;
  create_list(&head,n);
  int res = check(head);
  res != -1 ? printf("%d",res : printf("No Loop") ;
  return 0;
}