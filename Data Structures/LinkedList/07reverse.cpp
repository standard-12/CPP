/* Reverse a linked list using iterative method*/
#include<iostream>
#include<conio.h>
using namespace std;
struct node{
    int data;
    node* link;
};
node *head;
void reverse(){
    struct node *current,*prev,*next;
    current=head;
    prev=NULL;
    while ( current != NULL)
    {
        next = current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head = prev;
}
void insert(int n){
    node* temp = new node();
    temp->data=n;
    temp->link=head;
    head=temp;
}
void print(){
    node* temp=head;
    while(temp != NULL)
    { printf("%d ",temp->data);
    temp=temp->link;
    }
    printf("\n");
}
int main()
{ head=NULL;
  insert(2);
  insert(7);
  insert(4);
  print();
  reverse();
  print();
  return 0;
}