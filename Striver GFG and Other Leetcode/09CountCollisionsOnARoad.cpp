#include<bits/stdc++.h>
using namespace std;

// This was my solution which worked but there was a simple solution

class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        int i=0;
        stack<char> st;
        int count=0;
        while(i<n){
            if(directions[i]!='L'){
                if(directions[i]=='R'){
                    while(!st.empty() && st.top()!='R') st.pop();
                    st.push(directions[i]);
                }
                else {
                    while(!st.empty() && st.top()!='L'){
                        if(st.top()=='R') count+=1;
                        st.pop();
                    }
                    st.push(directions[i]);
                }
            }
            else if(!st.empty()){
                if(st.top()=='R') {
                    count+=2;
                    st.pop();
                }
                while(!st.empty()){
                    st.pop();
                    count+=1;
                }
                st.push('S');
            }
            i++;
        }
        return count;
    }
};
/*
cars on left side which are moving in left direction are never going to collide,
Similarly, cars on right side which are moving right side are never going to collide.

In between them every car is going to collide.
*/

class Solution {
    public:
     int countCollisions(string directions) {
        int left = 0, right = directions.length() - 1;
        
        while (left < directions.length() && directions[left] == 'L') {
            left++;
        }
        
        while (right >= 0 && directions[right] == 'R') {
            right--;
        }
        
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') {
                count++;
            }
        }
		//combining these three loops - TC : O(N).
        
        return count;
    }
};