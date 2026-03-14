#include<bits/stdc++.h>
using namespace std;

// Approach 1 -
class MinStack {
    stack<int> s1;
    stack<int> mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(mini.empty() || mini.top()>val ) mini.push(val);
        else mini.push(mini.top());
    }
    
    void pop() {
        s1.pop();
        mini.pop();
    }
    
    int top() {
        int val=s1.top();
        return val;
    }
    
    int getMin() {
        return mini.top();
    }
};

// Approach 2 - O(1) for all operations O(n+k)-Space Complexity where k is no of time mini getting updated
class MinStack {
    stack<int> st;
    int min;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty() || val<=min){
            st.push(min);
            min=val;
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top()==min){
            st.pop();
            min=st.top();
            st.pop();
        }
        else {
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};
// Approach 3 - 
#include <stack>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() { }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if (val < mini) {
                // encode previous min into the pushed value
                st.push(2LL * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return; // safe guard; depends on your API expectations

        long long topVal = st.top();
        st.pop();
        if (topVal < mini) {
            // topVal was encoded, decode previous minimum
            mini = 2LL * mini - topVal;
        }
        // otherwise mini remains unchanged
    }

    int top() {
        // assume non-empty; if you want safety, check st.empty() first
        long long topVal = st.top();
        if (topVal < mini) return (int)mini; // encoded => actual top is current min
        return (int)topVal;
    }

    int getMin() {
        // assume non-empty
        return (int)mini;
    }

    bool empty() const {
        return st.empty();
    }
};
