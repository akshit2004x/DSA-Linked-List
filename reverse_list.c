#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node * head=NULL;
struct node * head1=NULL;
struct node * head2=NULL;
void insertathead(int value)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
    
}
void insertathead1(int value)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head1;
    head1=newnode;
    
}
void display(struct node * r)
{
    struct node *temp=r;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reverse()
{
    struct node *prevnode=NULL,*currnode=head,*nextnode;
    while(currnode!=NULL)
    {
        nextnode=currnode->next;
        currnode->next=prevnode;
        prevnode=currnode;
        currnode=nextnode;
    }
    head=prevnode;

}
void compare()
{
    int f=0;
    struct node *list1=head;
    struct node* list2=head1;
    if(list1==NULL && list2==NULL)
    {
        f=1;
    }
    else
    {
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->data==list2->data)
            {
                list1=list1->next;
                list2=list2->next;
                f=f++;
            }
            else
            {
                f=0;
                break;
            }
        }
    }
    if(f>0)
        printf("linked list are equal");
    else
        printf("NOTT EQUAL");
}
void merge()
{
    //printf("1");
    struct node* temp1=head;
    struct node *temp2=head1;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp2;
}
struct node * sortedLinkedlistMerge()
{
    struct node *p=head,*q=head1;
    struct node *newnode;
    if(p==NULL)
    {
        newnode=q;
    }
    if(q==NULL)
    {
        newnode=p;
    }
    if(p!=NULL && q!=NULL)
    {
        if(p->data<=q->data)
        {
            newnode=p;
            p=newnode->next;
        }
        else
        {
            newnode=q;
            q=newnode->next;
        }
    }
    head2=newnode;
    while(p!=NULL && q!=NULL)
    {
        if(p->data<=q->data)
        {
            newnode->next=p;
            newnode=p;
            p=newnode->next;
        }
        else
        {
            newnode->next=q;
            newnode=q;
            q=q->next;
        }
    }
    if(p==NULL)
        newnode->next=q;
    if(q=NULL)
        newnode->next=p;
    return head2;
}
/*
int getNode(SinglyLinkedListNode* llist, int positionFromTail) 
{
    struct SinglyLinkedListNode * temp=llist,*p=llist;
    int len=0,d;
    while(temp!=NULL)
    {
        len=len+1;
        temp=temp->next;
    }
    positionFromTail=len-positionFromTail;
    for(int i=1;i<positionFromTail;i++) 
    {
        p=p->next;
    }
    d=p->data;
    return d;
}*/
void duplicate()
{
    struct node *temp=head,*nex=head->next,*prev=head;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            temp->next=temp->next->next;
        }
        else
        {
            temp=temp->next;
        }
    }
}
void mergetwopoints()
{
    struct node *temp1=head1,*temp2=head;
    while(temp1!=NULL)
    {
        while(temp2!=NULL)
        {
            if(temp1->data==temp2->data)
            {
                printf("%d",temp1->data);
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
void mergetwopoints1()
{
    struct node *temp1=head1,*temp2=head;
    while(temp1!=temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;
        if(!temp1)
            temp1=head1;
        if(!temp2)
            temp2=head;
    }
    return temp1->data;
}
int main()
{
    insertathead1(1);
    insertathead1(2);
    insertathead1(3);
    //display(head1);
    //reverse();
    insertathead(1);
    insertathead(3);
    insertathead(4);
    //insertathead(3);
    //insertathead(3);
   // display(head);
    //compare();
   // merge();
   // display(head);
   // head2=sortedLinkedlistMerge();
   // display(head2);
   //duplicate();
   //display(head);
   mergetwopoints();
}