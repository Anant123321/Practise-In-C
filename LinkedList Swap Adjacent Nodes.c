#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}node;

void print(node * head)
{
	node * current=head;
	while(current != NULL)
	{
		printf("%d ",current->data);
		current=current->next;
	}
}

void create(int n,node ** head)
{
	int i=0;
	node * current=NULL;
    for(i=0;i<n;i++)
    {
    	node * newnode=(node *)malloc(sizeof(node));
    	scanf("%d",&newnode->data);
    	newnode->next==NULL;
    	if(i==0)
    	{
    		*head=newnode;
    		current=newnode;
		}
		else
		{
			current->next=newnode;
			current=newnode;
		}
	}
	current->next=NULL;
}

node * swap(node * head)
{
	node * first=head;
	node * second=NULL;
	if(first)
	{
		second=first->next;
	}
	if(first==NULL || second==NULL)
	{
		return first;
	}
	else
	{
		first->next=swap(second->next);
		second->next=first;
		return second;

	}
}

int main()
{
	int n=0;
	node * head=NULL;
	scanf("%d",&n); 
	create(n,&head);
	head=swap(head);
	print(head);
	return 0;
}
