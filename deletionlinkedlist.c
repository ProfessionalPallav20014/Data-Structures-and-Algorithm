#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node * next;
};
void linkedlistraversal(struct Node * ptr){
    while (ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
// this function will delete the first element of linked list
struct Node *deletefirst(struct Node * head){
    struct Node * ptr = head;
    head=head->next;
    free(ptr);
    return head;
}
// this function will delete the element between the linked list at some index
struct Node * deleteatIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q=p->next;
    int i=0;
    while (i<index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}
// this function will delete the last node
struct Node * deleteatEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q=p->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
// this function will delete a particular value
struct Node * deleteafter(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q=p->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if (q->data==value){
        p->next=q->next;
        free(q);
    }
    return head;
}


// main
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
    fourth->next=NULL;

    // linkedlistraversal(head);
    head=deleteafter(head, 9);
    linkedlistraversal(head);
    return 0;

}
