#include <iostream>
using namespace std;

class  Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAthead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAttail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtposition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        insertAthead(head,d);
        return;
    }
    
    Node* temp = head;
    int cnt = 1;

    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAttail(tail,d);
        return;
    }

    Node* newnode = new Node(d);
    newnode->next = temp->next;
    temp->next = newnode;

}

void deletenode(int position, Node* &head){
    if(position==1){
        Node* temp = head;
        head = head->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        int cnt=1;
        Node* prev = NULL;
        Node* cur = head;

        while(cnt<position){
            prev = cur;
            cur = cur->next;
            cnt++;
        }

        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}

