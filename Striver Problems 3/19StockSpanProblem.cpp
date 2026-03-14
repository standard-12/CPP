#include<bits/stdc++.h>
using namespace std;

// I solved it in first try yeee 
// And there was no errors in my first code 
 // Actually i need not store the index in a stack and answer in a separate vector instead  i can store the answer directly in stack instead of the vector

class StockSpanner {
    stack<int> st;
    stack<int> stIndex;
    vector<int> vec;
    int i=0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;
        while(!st.empty() && st.top()<=price){
            int index=stIndex.top();
            stIndex.pop();
            st.pop();
            ans+=vec[index];
        }
        st.push(price);
        vec.push_back(ans);
        stIndex.push(i);
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


 
 class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {

    }
    
    int next(int price) {
        int ans=1;
        while(!st.empty() && st.top().first<=price){
            ans+=st.top().second;
            st.pop();
        }
        st.push({price,ans});
        return ans;
    }
};
 