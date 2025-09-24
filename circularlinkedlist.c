#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
};

void circularTraversal(struct Node *head){
    struct Node *ptr=head;
    do{
        printf("ELement: %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

struct Node * insertFirst(struct Node * head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p=head->next;
    while (p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=4;
    head->next=second;
    second->data=5;
    second->next=third;
    third->data=9;
    third->next=fourth;
    fourth->data=7;
    fourth->next=head; // Make the list circular

    // circularTraversal(head);
    head=insertFirst(head, 22);
    circularTraversal(head);
    return 0;

}

