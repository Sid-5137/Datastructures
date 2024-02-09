#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

int lengthlist(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAttail(Node* &head, Node* &tail,int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtposition(Node* &head, Node* &tail, int position, int d){
    if(position == 1){
        insertAtHead(head,tail, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAttail(head,tail,d);
        return;
    }

    Node* newnode = new Node(d);

    newnode->next = temp->next;
    temp->next = newnode;
    head = temp->next;
    temp->next = NULL;
    delete temp;
}

void deleteNode(Node* &head, int position){
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}