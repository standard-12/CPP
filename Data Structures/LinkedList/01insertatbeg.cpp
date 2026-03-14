/* This is a simple implementation of linked list where we create insert 
function which will insert a element at the begining of the list*/
#include<iostream>
#include<stdio.h>
using namespace std;
struct node {
    int data;
    node* link;
};
node* head;
void insert(int a);
void print();
int main(){
    head=NULL;
    insert(3);
    insert(5);
    insert(7);
    insert(1);
    print();
    return 0;
}
void insert(int a){
    node* temp = new node();
    temp->data=a;
    temp->link=head;
    head=temp;
    }
void print(){
    node* temp=head;
    while(temp !=NULL)
    {   
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
