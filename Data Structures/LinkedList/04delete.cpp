/* In this program we will create a linked list and delete a element from specified positon*/
#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
    int data;
    node* link; // In c it should be written as sturct node* link;
};
node* head; 
void insert(int x); // Inserting at the end of list
void Print(); // Printing the list
void Delete(int i);
int main(){
    head = NULL;
    insert(2);
    insert(5);
    insert(6);
    Print();
    int n;
    cout<<"At what position >"<<endl;
    cin>>n;
    Delete(n);
    Print();
}

void insert(int x)
{ node* temp1 = new node(); // In c we should write struct node* temp = (node*)malloc(sizeof(struct node));
  temp1->data=x;
  temp1->link=NULL;
  if (head == NULL){
    head = temp1;
  }
  else{
  node* temp2 = head;
  while (temp2->link != NULL)
  {
    temp2=temp2->link;
  }
  
  temp2->link=temp1;
  temp1->link=NULL;  
  } 
}
void Print(){
    node* temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void Delete(int i)

{    node* temp=head;
     if(i==1){
        head=temp->link;
        free(temp);
        return;
     }
     for (int k=0;k<i-2;k++) // note i-2f
     {  
        temp=temp->link;
     }

     node* temp2=temp->link;
     temp->link=temp2->link;
     free(temp2);
}





