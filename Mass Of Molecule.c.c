#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node * next; 
}node;

void pop(node **head)
{
    (*head)=(*head)->next;
}
int top(node * head)
{
    return head->data;
}
void push(int value,node ** head)
{
    node * newnode=(node *)malloc(sizeof(node));
    newnode->next=(*head);
    newnode->data=value;
    (*head)=newnode;
}

int poll(node **head)
{
    if((*head)==NULL)return 0;
    int res=(*head)->data;
    (*head)=(*head)->next;
    return res;
}

void print(node* head)
{
    int sum=0;
    while(head!=NULL)
    {
        sum=sum+head->data;
        head=head->next;
        
    }
    printf("%d",sum);
}
int main(void)
{
    char c;
    scanf("%d",&c);
    node * head= NULL;
    int brackets=0,num=0,sum=0,value=0;
    while(c!='\n')
    {
        switch(c)
        {
            case 'C':push(12,&head);
                     break;
            case 'H':push(1,&head);
                     //printf("1push");
                     break;
            case 'O':push(16,&head);
                     //printf("16push");
                     break;
            case '(':brackets--;
                     push(brackets,&head);
                     break;
            case ')':sum=0;
                     while(top(head)!=brackets)
                     {
                        sum=sum+poll(&head);
                     }
                     pop(&head);
                     //printf("sum=%d\n",sum);
                     push(sum,&head);
                     brackets++;
                     break;
            default: if(c>='0' && c<='9')
                     {
                         num=(int)(c-'0');
                         value=num*poll(&head);
                         push(value,&head);
                         break;
                     }
        }
        scanf("%c",&c);
    }
    print(head);
    return 0;
}