#include <stdio.h>
#include <stdlib.h>
/*
Operations to be performed:
1.Deletion of first element
2.Deletion between the list
3.Deletion of the end of the list
4.Deletion of a particular element
*/

struct Node{
    int data;
    struct Node * next;
};
void linkedlistTraversal(struct Node * ptr){
    while (ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr=ptr->next;
    }
}
void deletionfirstelement(struct Node** head){
    struct Node * ptr= (*head); // the ptr will point at the head
    (*head)=(*head)->next; // the head will be updated to the next element or the second element
    free(ptr); // then the dynamically allocated memory of ptr will be freed 
    printf("First element deleted successfully\n");
}

// main
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // allocate the memory in the heap
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    // link the nodes
    head->data=78; // can also be written as (* head).data
    head->next=second;
    second->data=45;
    second->next=third;
    third->data=61;
    third->next=fourth;
    fourth->data=80;
    fourth->next=NULL;


    linkedlistTraversal(head);
    deletionfirstelement(head);
    linkedlistTraversal(head);
    return 0;
}