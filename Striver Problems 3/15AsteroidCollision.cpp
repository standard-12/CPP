#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(asteroids[i]<0){
                if(st.empty() || st.top()<0) st.push(asteroids[i]);
                else {
                    while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                        st.pop();
                    }
                    if(!st.empty() && st.top()==abs(asteroids[i])){
                        st.pop();
                    } 
                    else if(st.empty() || st.top()<abs(asteroids[i])) st.push(asteroids[i]); // Here st.top()<0 instead of st.top() <abs(asteroids[i]) makes better sense both are right though
                }
            }
            else {
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end()); // Because ans was built from stack so we should reverse it
        return ans;
    }
};