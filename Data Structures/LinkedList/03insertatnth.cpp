/* This program is to insert a node at the specified position*/
#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
    int data;
    node* link;
};
node* head;
void insert(int val, int n);  //In this program we are assuming that user will input valid indices
void print();
int main(){
    head=NULL;
    insert(7,1);
    print();
    insert(3,2);
    print();
    insert(5,3);
    print();
    insert(2,1);
    print();
    insert(3,1); 
    print();
    insert(4,6);
    print();
}
void insert(int val,int n){
   node* temp = new node();
   if(n==1){
    temp->data=val;
    temp->link=head;
    head=temp;
    return;
   }
   temp->data=val;
   node *temp2=head;
   for(int i=0;i<n-2;i++)
   { temp2=temp2->link;
   }
   temp->link=temp2->link;
   temp2->link=temp;
}
void print(){
    node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}