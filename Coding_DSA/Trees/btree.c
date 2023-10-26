#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(struct node* root,int data){
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
};

struct node* createtree(struct node* root){
    int data;
    printf("Enter the data: \n");
    scanf("%d",&data);
    root = (struct node*)malloc(sizeof(struct node*));
    root = createnode(root,data);
    if(data==-1){
        return NULL;
    }
    printf("Enter the data to the left of %d: ",data);
    root->left = createtree(root->left);
    printf("Enter the data to the right of %d: ",data);
    root->right = createtree(root->right);
};


int main(){
    struct node* root = NULL;
    createtree(root);
    return 0;
}
