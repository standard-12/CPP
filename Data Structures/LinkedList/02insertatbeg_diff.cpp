/* In this we will be doing the same simple thing we did in insertatbeg.cpp but here instead of declaring head as a global variable 
we declare it as local to int main() and use pointer to pointer */
#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
    int data;
    node* link;
};
void insert(int n,node** head);/* Since after each insertion we should change the value in head we must pass the adress of head to 
insert so it is declared as node** head (contrary to node * head in print(). This can be done in another way by retruning head from 
insert i.e head = insert (head,n) then we should declare function as node* insert(node* head,int n); )*/

void print(node* head);  // Here we need not the chaneg the value of head

int main(){
node* head = NULL;
insert(7,&head);
insert(8,&head);
insert(6,&head);
print(head);
return 0;
}

void insert(int n,node** head){
    node* temp = new node();
    temp->data=n;
    temp->link= *head;
    *head = temp;
}
void print(node* head){
    while(head !=NULL)
    {   
        printf("%d ",head->data);
        head=head->link;
    }
}