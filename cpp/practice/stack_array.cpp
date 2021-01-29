#include <stdio.h>

using namespace std;

#define STACK_SIZE 100
int top=-1;
int a[STACK_SIZE];

void push(int n){
    if(top>=STACK_SIZE){
        return STACK_FULL();
    }
    else
    {
        a[++top]=n;
    }
}

void pop(){
    if(top==-1){
        return STACK_EMPTY();
    }
    else a[top--];
}

void STACK_FULL(){
    printf("Stack is full");
}

void STACK_EMPTY(){
    printf("Stack is empty");
}