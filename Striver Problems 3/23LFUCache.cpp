#include<bits/stdc++.h>
using namespace std;
   
   struct Node{
        int val,key,cnt;
        Node* prev;
        Node* next;

        Node(int key_,int val_){
            this->key=key_;
            this->val=val_;
            this->cnt=1;
            this->next=NULL;
            this->prev=NULL;
        }
    };

    struct List{
        int size;
        Node* head;
        Node* tail;

        List(){
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;
            size=0;
        }

        void addFront(Node* node){
            Node* temp=head->next;
            node->next=temp;
            node->prev=head;
            temp->prev=node;
            head->next=node;
            size++;
        }

        void removeNode(Node* delnode,bool toDelete=false){
            Node* delprev=delnode->prev;
            delprev->next=delnode->next;
            delnode->next->prev=delprev;
            if(toDelete) delete delnode;
            size--;
        }
    };


class LFUCache {
    unordered_map<int,Node*> mp;
    unordered_map<int,List*> freqList;
    int maxSize;
    int minFreq;
    int currSize;
public:
    LFUCache(int capacity) {
        maxSize=capacity;
        minFreq=0;
        currSize=0;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* temp=mp[key];
            int val=temp->val;
            updateFreqList(temp);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* temp=mp[key];
            temp->val=value;
            updateFreqList(temp);
        }
        else {
            if(currSize==maxSize){
                List* list=freqList[minFreq];
                mp.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev,true);
                currSize--;
            }
            currSize++;
            minFreq=1;
            List* newList=new List();
            if(freqList.count(minFreq)){
                newList=freqList[minFreq];
            }
            Node* node=new Node(key,value);
            newList->addFront(node);
            mp[node->key]=node;
            freqList[minFreq]=newList;
        }
    }

    void updateFreqList(Node* node){
        mp.erase(node->key);
        freqList[node->cnt]->removeNode(node);
        if(node->cnt==minFreq && freqList[node->cnt]->size==0 ){
            minFreq++;
        }
        List* nextFreqList=new List();
        if(freqList.count(node->cnt + 1)){
            nextFreqList=freqList[node->cnt + 1];
        }
        node->cnt+=1;
        nextFreqList->addFront(node);
        freqList[node->cnt]=nextFreqList;
        mp[node->key]=node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */