#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
void insertathead(int v)
{
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=v;
    newnode->prev=NULL;
    newnode->next=head;
    head=newnode;
    printf("Done ");
};
void insertAfter(int n,int val)
{
    struct node * temp=head,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    while(temp!=NULL)
    {
        if(temp->data==n)
            break;
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    if(newnode->next!=NULL)
        newnode->next->prev;
    printf("Done ");
}
void reverse()
{
    struct node *temp=head,*s=NULL;
    while(temp!=NULL)
    {
        s=temp->prev;
        temp->prev=temp->next;
        temp->next=s;
        temp=temp->prev;
    }
    if (s!= NULL)
        head =s;
};
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{

    insertathead(3);
    insertathead(2);
    insertathead(1);
    //insertAfter(2,4);
    display();
    reverse();
    display();
}