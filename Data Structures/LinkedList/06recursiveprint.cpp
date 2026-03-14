/* In this program we print (FORWARD AND REVERSE) a linked list using recursion*/
#include<stdio.h>
using namespace std;
struct node{
    int data;
    node* link;
};
struct node* head;                
void Rprint(node* p){                 // Note the difference between the order of recursive call and print command
    if(p==NULL){
        return;
    }
    printf("%d ",p->data);
    Rprint(p->link);  //Recursive Call
}
void reverseRprint(node* p){
    if(p==NULL){
        printf("\n");
        return;
    }
    reverseRprint(p->link); //Recursive Call
    printf("%d ",p->data); 
}
void insert(int n){
    node* temp = new node();
    temp->data=n;
    temp->link=head;
    head =temp;    
}

int main(){
    head = NULL;
    insert(4);
    insert(3);
    insert(2);
    insert(5);
    Rprint(head);
    reverseRprint(head);
    return 0;
}