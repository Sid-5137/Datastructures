#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

void insertathead(struct node* head,int data){
    struct node* temp = createnode(data);
    temp->link = head;
    temp = head;
}

void display(struct node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head->link;
    }
}

int main(){
    struct node* head = NULL;
    insertathead(head,10);
    display(head);
    return 0;
}
