#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *insertatfirst(struct node *head,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node *));
    ptr->next=head;
    ptr->data=data;
    head=ptr;
    return head;
}
struct node *insertatbetween(struct node *head,int data,int index)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node *));
    struct node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        printf("%d ",p->data);
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct node *insertatend(struct node *head,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node *));
    ptr->data=data;
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct node *insertafternode(struct node *head,struct node *prevnode,int data)
{
    struct  node *ptr=(struct node *)malloc(sizeof(struct node *));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}
void linkedlisttraversal(struct node *ptr)  
{
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node *head ;
    struct node *second ;
    struct node *third ;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    struct node * f=(struct node *)malloc(sizeof(struct node));
    struct node * fi=(struct node *)malloc(sizeof(struct node));
    struct node * s=(struct node *)malloc(sizeof(struct node));
    //node 1
    head->data =1;
    head->next=second;
    //node 2 
    second->data =2;
    second->next=third;
    //node 3
    third->data =3;
    third->next=f;

    f->data =4;
    f->next=fi;

    fi->data =5;
    fi->next=s;

    s->data =6;
    s->next=NULL;
    //linkedlisttraversal(head);
    //printf("%d",head);
    return 0;
}