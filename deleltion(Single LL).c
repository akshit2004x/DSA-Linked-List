#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node * deleteFirst(struct node *head)
{
    struct node * ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct node * deleteAtIndex(struct node * head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct node * deleteAtLast(struct node * head)
{
    struct node *p = head;
    struct node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct node * deleteByValue(struct node * head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
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
    //node 1 
    head->data =1;
    head->next=second;
    //node 2
    second->data =2;
    second->next=third;
    //node 3
    third->data =3;
    third->next=NULL;
    linkedlisttraversal(head);
    head=deleteFirst(head);
    //head=deleteAtIndex(head,1);
    //head=deleteAtLast(head);
   // head=deleteByValue(head,2);
    linkedlisttraversal(head);
    return 0;
}
