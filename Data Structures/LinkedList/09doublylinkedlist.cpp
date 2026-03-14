#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    node* next;
    node* prev;
};
struct node* head;

struct node* Getnewnode(int x){
    node* newnode = new node();
    newnode->data=x;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void insertathead(int x){
    node* newnode=Getnewnode(x);
    if(head==NULL) {
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;    
}

void print(){
     node* temp=head;
     printf("Forward :");
     while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;
     }
     printf("\n");
}

void reverseprint(){
    node* temp =head;
    if(temp==NULL) return; // for empty list ...these cases were not considered in sLL codes
    printf("Reverse :");
    while(temp->next !=NULL){ // going to last node
        temp=temp->next;
    }
    while(temp != NULL ){
        printf("%d ", temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void insertattail(int x){
    node* newnode=Getnewnode(x);
    node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

int main(){
    head = NULL;
    insertathead(2);  print();    reverseprint();
    insertathead(5);  print();    reverseprint();
    insertathead(7);  print();    reverseprint();
    insertattail(9);  print();    reverseprint();
    return 0;
}
