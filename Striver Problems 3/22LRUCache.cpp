#include<bits/stdc++.h>
using namespace std;

// Yeeee I came up with this on my own and this is the optimal solution
// Wowww even the front rear dummy node idea is right very niceee


class LRUCache {
    struct Node{
        int val;
        int key;
        Node* prev;
        Node* next;

        Node(int val){
            this->val=val;
            this->prev=NULL;
            this->next=NULL;
        }
    };
    int capac;
    int currSize;
    Node* front;
    Node* rear;
    unordered_map<int,Node*> mp;

public:
    LRUCache(int capacity) {
        capac=capacity;
        currSize=0;
        front=new Node(-1);
        rear=new Node(-1);
        front->next=rear;
        rear->prev=front;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* temp=mp[key];
            delink(temp);
            insertAtRear(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* temp=mp[key];
            delink(temp);
            insertAtRear(temp);
            temp->val=value;
        }
        else {
            Node* temp=new Node(value);
            temp->key=key;
            insertAtRear(temp);
            currSize++;
            if(currSize>capac){
                removeFromFront();
            }
            mp[key]=temp;
        }
        
    }

    void delink(Node* temp){
             temp->prev->next=temp->next;
             temp->next->prev=temp->prev;
    }

    void insertAtRear(Node* temp){
        rear->prev->next=temp;
        temp->prev=rear->prev;
        temp->next=rear;
        rear->prev=temp;
    }

    void removeFromFront(){
        Node* del=front->next;
        front->next=del->next;
        del->next->prev=front;
        mp.erase(del->key);
        delete del;
        currSize--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */