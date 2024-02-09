#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildtree(Node* root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root = new Node(data);
    
    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data in left of "<<data<<endl;
    root -> left = buildtree(root -> left);
    cout<<"Enter the data in right of "<<data<<endl;
    root -> right = buildtree(root->right);
    return root;

}

void levelOrdertraverse(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL){
            //previous level is completed
            if(temp == NULL){
    
                //For new line
                cout<<endl;

                //Checks if the level has any child nodes
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

int main(){
    Node* root = NULL;
    
    //Creating a tree;
    root = buildtree(root);

    levelOrdertraverse(root);   

    return 0;
}