/* Here we actually reverse the linked list rather than only printing like recursiveprint.cpp*/
#include<stdio.h>
using namespace std;
struct node{
    int data;
    node* link;
};
struct node* head;
void insert(int n, int pos){
    node* temp=new node();
    temp->data=n;
    temp->link=NULL;
    if(pos == 1){
        temp->link=head;
        head=temp;
        return;
    }
    node* temp2 = head;
    for (int i =0;i<pos-2;i++){
        temp2=temp2->link;
    }
        temp->link = temp2->link;
        temp2->link =temp;
}
void print(){
    node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp=temp->link;
    }
}
/*
if(p->link->link==NULL){
        head = p->link;
        p->link->link=p;
        p->link=NULL;
        return;
    }
    reverse(p->link);
    p->link->link=p;
    p->link=NULL;

    this was figured out by me before watching video
    */
void reverse(node* p){           // this was in the fcc video 
    if(p->link==NULL){
        head =p;
        return;
    }
    reverse(p->link);
    node* q=p->link;
    q->link=p;
    p->link=NULL;    
}
int main(){
    head = NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    print();
    reverse(head);
    print();

}


