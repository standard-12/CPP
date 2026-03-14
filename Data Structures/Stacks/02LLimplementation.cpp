#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node* top = NULL;

void push(int x){
 struct node* temp=(struct node*)malloc(sizeof(struct node*));
 temp->data=x;
 temp->link=top;
 top=temp;
}
void pop(){
    if(top ==NULL){
        printf("Stack is empty");
        return;
    }
    node* temp=top;
    top=top->link;
    free(temp); 
}
void print(node* p){  //Printing the linked list in reverse order will give us the stack
    if(p==NULL){
        printf("\n");
        return;
    }
    print(p->link); //Recursive Call
    printf("%d ",p->data);

}           
int main(){
    push(5); print(top);
    push(4);print(top);
    pop();print(top);
    push(2);print(top);
    return 0;
}
