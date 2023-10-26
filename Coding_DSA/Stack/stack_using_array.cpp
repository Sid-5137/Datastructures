#include <iostream>
using namespace std;

class Stack {
    public:
        int* arr;
        int size;
        int top;
        Stack(int size){
            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element){
            if(size - top > 1){
                top++;
                arr[top] = element;
            }
            else
                cout<<"Stack Overflow"<<endl;
        }

        void pop(){
            if(top>=0){
                top--;
            }
            else
                cout<<"Stack Underflow"<<endl;
        }

        int peek(){
            if(top>=0){
                return arr[top];
            }
            else{
                cout<<"Stack is empty"<<endl;
                return -1;
            }
        }

        bool isempty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }

        int isfull(){
            if(top == size-1){
                return 1;
            }
            else{
                return 0;
            }
        }

        void display(){
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
        }
};

int main(){
    int size;
    cout<<"Enter the size of stack: ";
    cin>>size;
    Stack s(size);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    s.pop();

    cout<<s.isfull()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.peek()<<endl;
    s.display();
    return 0;
}