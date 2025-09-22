# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void linklistTraveresal(struct Node *ptr){
    while (ptr != NULL) {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data=23;
    head->next=second;
    second->data=45;
    second->next=third;
    third->data=89;
    third->next=fourth;
    fourth->data=14;
    fourth->next=fifth;
    fifth->data=28;
    fifth->next=NULL;

    linklistTraveresal(head);
    return 0;
}