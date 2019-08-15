#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}node;

node * reverse(node *, node*);

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

node * reversek(node * head,int k)
{
	int i=1;
	node * ptr=head;
	node * btr=head;
	while(btr->next != NULL && i<k)
	{
		i++;
		btr=btr->next;
	}
	if(btr->next==NULL)
	{
		return (reverse(ptr,btr));
	}
	else
	{
		btr->next=reversek(btr->next,k);
		return reverse(ptr,btr);
	}
}

node* reverse(node * start, node * end)
{
	node * first=start;
	node * second=NULL;
	if(first)
	{
		second=first->next;
	}
	if(first==end)
	{
		return first;
	}
	else
	{
		node * h=reverse(second,end);
		first->next=second->next;
		second->next=first;
		return h;

	}
}
int main()
{
	int n=0;
	node * head=NULL;
	scanf("%d",&n); 
	create(n,&head);
	printf("Enter k");
	int k=0;
	scanf("%d",&k);
	head=reversek(head,k);
	print(head);
	return 0;
}
