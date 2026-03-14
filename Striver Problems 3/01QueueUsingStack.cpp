#include<bits/stdc++.h>
using namespace std;
// This was my solution i was keeping in mind the implementation of back also
// So i kept the last inserted elelment in s1 and i was inserting at bottom for s2
class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {        
    }
    
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
            return;
        }
        else {
            insertAtBottom(s2,s1.top());
            s1.pop();
            s1.push(x);
        }
    }
    
    int pop() {
        if(s2.empty()){
            int val=s1.top();
            s1.pop();
            return val;
        }
        int val=s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if(s2.empty()) return s1.top();
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty()) return true;
        else return false;
    }
    void insertAtBottom(stack<int>& st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int val=st.top();
        st.pop();
        insertAtBottom(st,x);
        st.push(val);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// the Amortized and the expected solution is given below
// This is the amortized version i.e for most of the operations its O(1)
// Consideres s1 as input box and s2 as output box
// But it has occasional O(n) actions. (like until we have a set of numbers in s2 we can perform pop in O(1) but if the s2 is empty)

 class MyQueue { 
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    void moveFromInputtoOutput(stack<int>& s1,stack<int>& s2){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    
    int pop() {
        moveFromInputtoOutput(s1,s2);
        int val=s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        moveFromInputtoOutput(s1,s2);
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};