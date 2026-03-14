// Implementation using arrays
#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top=-1;
void push(int x){
    if(top == MAX_SIZE-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    A[++top]=x;
}
void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    top--;        // In some cases pop function returns the top element
}
void print(){
    int i;
    printf("Stack :");
    for(i=0;i<=top;i++)
        printf("%d ",A[i]);
    printf("\n");
}
int main(){  
    push(2);print();
    push(5);print();
    push(10);print();
    pop();print();
    push(1);print();

}
