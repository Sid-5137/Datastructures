#include <stdio.h>
 
struct Node{
    struct Node* lchild;
    int data;
    struct Node* rchild;
}*root=NULL;
 
void Insert(int key) {
 
    struct Node* t = root;
    struct Node* r=NULL,*p;
 
    // root is empty
    if (root == NULL){
        p = new Node;
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;
    }
 
    while(t != NULL){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }
 
    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;
 
    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }
 
}
 
void Inorder(struct Node* p) {
    if (p){
        Inorder(p->lchild);
        printf("%d",p->data);
        Inorder(p->rchild);
    }
}
 
struct Node* Search(int key) {
    struct Node* t = root;
    while (t != NULL){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return NULL;
}
 
 
int main() {
 
    BST bst;
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);
 
    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;
 
    // Search
    Node* temp = bst.Search(2);
    if (temp != NULL){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
 
    return 0;
}