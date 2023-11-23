#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode){
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;
        return newnode;
    }
}

void insertAtHead(struct node** head,struct node** tail,int d){
    struct node* temp = createnode(d);
    if(temp){
        if(head==NULL){
            *head = temp;
            *tail = temp;
        }
        else{
            temp->next = *head;
            (*head)->prev = temp;
            *head = temp;
        }
    }
}

void insertAtTail(struct node** head,struct node** tail,int d){
    struct node* temp = createnode(d);
    if(temp){
        if(head==NULL){
            *head = temp;
            *tail = temp;
        }
        else{
            (*tail)->next = temp;
            temp->prev = *tail;
            *tail = temp;
        }
    }
}

void insertAtPosition(struct node** head, struct node** tail, int position, int data) {
    if (position == 1) {
        insertAtHead(head, tail, data);
    } else {
        struct node *temp = *head;
        int cnt = 1;
        
        while (cnt < position - 1 && temp != NULL) {
            temp = temp->next;
            cnt++;
        }

        if (temp == NULL) {
            insertAtTail(head, tail, data);
        } else {
            struct node* newnode = createnode(data);

            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}


void print(struct node* head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("%p \n",NULL);
}

int main(){
    int root;
    printf("Enter the root node: ");
    scanf("%d",&root);
    struct node* head = createnode(root);
    struct node* tail = head;
    if(head){
        insertAtTail(&head,&tail,2);
        insertAtHead(&head,&tail,10);
        insertAtPosition(&head,&tail,2,30);
        print(head);
    }
    return 0;
}