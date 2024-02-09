#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAtHead(struct node** head, int data) {
    struct node* temp = createNode(data);
    if (temp) {
        temp->next = *head;
        *head = temp;
    }
}

void insertAtTail(struct node** tail, int data) {
    struct node* temp = createNode(data);
    if (temp) {
        if (*tail == NULL) {
            *tail = temp;
        } 
        else{
            struct node* current = *tail;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }
}

void insertAtPosition(struct node** head,struct node** tail,int position,int data){
    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    
    struct node* temp = *head;

    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next = NULL){
        insertAtTail(head,data);
        return;
    }

    struct node* newnode = createNode(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletenode(struct node** head,int position){
    if(position == 1){
        struct node* temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        free(temp);
    }
    else{
        int cnt = 1;

        struct node* prev = NULL;
        struct node* cur = *head;

        while(cnt<position){
            prev = cur;
            cur = cur->next;
            cnt++;
        }

        prev->next = cur->next;
        cur->next = NULL;
        free(cur);

    }
}

void print(struct node* head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main() {
    int head_data;
    printf("Enter the head node data: ");
    scanf("%d", &head_data);

    struct node* Head = createNode(head_data);
    struct node* Tail = Head;

    if (Head) {
        insertAtHead(&Head, 20);
        insertAtTail(&Tail, 10);
        insertAtTail(&Tail, 40);
        insertAtPosition(&Head,&Tail,4,50);
        deletenode(&Head,4);
        print(Head);
    }

    return 0;
}
