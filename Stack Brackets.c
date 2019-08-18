#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	char data;
    node * next; 
}node;


void push(char value,node ** head)
{
    node * newnode=(node *)malloc(sizeof(node));
    newnode->next=(*head);
    newnode->data=value;
    (*head)=newnode;
}

char poll(node **head)
{
	if((*head)==NULL)return 'x';
    char res=(*head)->data;
    (*head)=(*head)->next;
    return res;
}

int check(node* head,int n)
{
	int i=0,count=0;
	char value;
	for(i=0;i<n;i++)
	{
		scanf("%c",&value);
		if(value=='(' || value=='{' || value=='[')
		{
             push(value,&head);
             count++;
		}
		else
		{
			count--;
			switch(value)
			{
				case ')':
				if(poll(&head)!='(')return 0;
				break;
				case ']':
				if(poll(&head)!='[')return 0;
				break;
				case '}':
				if(poll(&head)!='{')return 0;
			}
		}
	}
	if(count==0)
    return 1;
    else
    return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	node * head=NULL;
	int a=check(head,n);
	printf("%d",a);
}