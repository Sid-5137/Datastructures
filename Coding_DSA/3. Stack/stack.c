#include <stdio.h>
#include <stdlib.h>

struct stack{
    int* arr;
    int size;
    int top;
};


struct stack* createStack(int size) {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    if (s) {
        s->arr = (int*)malloc(sizeof(int) * size);
        s->size = size;
        s->top = -1;
    }
    return s;
}

void push(struct stack* s,int element){
    if((s->size - s->top)>1){
        s->top++;
        s->arr[s->top] = element;
    }
    else{
        printf("The stack is FULL!");
    }
}

void pop(struct stack* s){
    if(s->top==-1){
        printf("The stack is EMPTY!");
    }
    else{
        s->top--;
    }
}

void printrev(struct stack* s){
    printf("Printing the stack in Reverse Order: \n");
    for(int i=0;i<=s->top;i++){
        printf("%d\n",s->arr[i]);
    }
}

void print(struct stack* s){
    for(int i=s->top;i>=0;i--){
        printf("%d\n",s->arr[i]);
    }
}

int main(){

    int size;
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    
    struct stack* st = createStack(size);
    push(st,1);
    push(st,2);
    push(st,3);
    pop(st);
    print(st);
    printrev(st);

    free(st->arr);
    free(st);

    return 0;
}