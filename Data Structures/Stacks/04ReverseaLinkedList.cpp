// Reversing a Linked List using Stack THE Recursion program is also using stack but its implicit (i.e in memory stack )
// This is using explicit stack
#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node* link;
};

node* head=NULL;

void insertatbeg(int x){
    node* temp=new node();
    temp->data=x;
    temp->link=head;
    head=temp;
}

void reverse(){
    stack<node*> S;
    node* temp=head;
    while(temp != NULL){
        S.push(temp);
        temp=temp->link;
    }
    head=S.top();
    temp=head;
    while(!S.empty()){
        temp->link=S.top();
        S.pop();
        temp=temp->link;
    }
    temp->link=NULL;
}

void print(){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}
int main(){
    insertatbeg(5);
    insertatbeg(6);
    insertatbeg(7);
    insertatbeg(8);
    print();
    reverse();
    print();
    return 0;
}
