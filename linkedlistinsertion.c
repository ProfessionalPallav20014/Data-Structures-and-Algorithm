#include <stdio.h>
#include <stdlib.h>
// linked list is just like a train not like array which has contiguous memory
struct Node{
    int data;
    struct Node * next; // this is the pointer pointing to the next data
};
void linkedlistTraversal(struct Node * ptr){
    while (ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr=ptr->next;
    }
}
// below function is used to insert a new node named ptr and the next of this node is connected to the head and data plus the node is returned
struct Node * insertatFirst(struct Node * head, int data){
    struct Node * ptr= (struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
};

// below function is used to insert a node between any two nodes
struct Node * insertbetween(struct Node * head, int data, int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while (i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

// below function is used to insert a node at the end
struct Node * insertatEnd(struct Node * head, int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    while (p->next!=NULL){
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

//below function is used for inserting a node after a node whose address is know to us
struct Node * insertafter(struct Node * head, struct Node * prevnode,int data){
    struct Node * ptr= (struct Node *)malloc(sizeof(struct Node));
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    ptr->data=data;
    return head;
};

// main 
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocate the memory in the heap
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));

    // link the nodes
    head->data=78; // can also be written as (* head).data
    head->next=second;
    second->data=45;
    second->next=third;
    third->data=6;
    third->next=NULL;
    linkedlistTraversal(head);
    printf("----------\n");
    head=insertafter(head, second, 83);
    linkedlistTraversal(head);

    return 0;
}