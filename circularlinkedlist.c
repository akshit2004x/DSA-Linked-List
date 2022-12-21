#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void linkedlisttraversal(struct node *head)  
{
    struct node *ptr=head;
    do
    {
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node* insertatfirst(struct node *head,int data)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p = head->next;
    while(p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
struct node *insertatlast(struct node *head,int data)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p = head->next;
    while(p!= head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return head;
}
void cycle()
{
    struct node *temp1=head,*temp2=head->next;
    while(temp1!=NULL)
    {
        if( temp1==temp2)
        {
            printf(" it is a cycle");
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    printf("not a cycle");
}
int main()
{
    struct node *head ;
    struct node *second ;
    struct node *third ;
    struct node *fourth ;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    //node 1
    head->data =1;
    head->next=second;
    //node 2
    second->data =2;
    second->next=third;
    //node 3
    third->data =3;
    third->next=fourth;
    //node 4
    fourth->data =4;
    fourth->next=head;
    linkedlisttraversal(head);
    cycle();
    return 0;
}