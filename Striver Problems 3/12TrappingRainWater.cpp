#include<bits/stdc++.h>
using namespace std;

// Since this was in stack list i though we should be using stack 
// So this was my first solution which got accepted but it is very complicated

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        while(i<n-1 && height[i]<height[i+1]) {
             i++; // Removing left side starting slope
        }
        while(j>0 && height[j]<height[j-1]){
          j--; // Removing right side ending slope
        }
        stack<int> st;
        int trappedWater=0;
        int currMax;
        if(i<=j) {
            currMax=height[i];
            st.push(height[i]); // Initiating the stack 
            i++;
        }
        while(i<=j){
            if(height[i]<currMax){
                st.push(height[i]);      
            }
            else {             // Resolving the stack when we encouter a greater or equal number to currMax;
                int temp=0;
                while(!st.empty() && st.top()<currMax){
                    temp+=currMax-st.top();
                    st.pop();
                }
                trappedWater+=temp;
                st.pop();
                st.push(height[i]);
                currMax=height[i];
            }
            i++;
        }
        int last=st.top();
        st.pop();
        int temp2=0;
        while(!st.empty()){  // If there was no greater element than currMax Still there is a chance of water logging
            int water=last-st.top();
            if(water>=0) temp2+=water;
            if(st.top()>last) last=st.top();  // Handling Local Maximas for e.g 8 2 3 "7" 4 5 6 etc
            st.pop();
        }
        trappedWater+=temp2;
        return trappedWater;

    }
};

// This is the most easy to understand solution ....Idea is a block can store a certain amount of water if there is 
// Greater element to its left side and to its right side also
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefMax(n,0);
        vector<int> suffMax(n,0);
        for(int i=0;i<n;i++){
            if(i==0) prefMax[i]=height[i];
            else prefMax[i]=max(prefMax[i-1],height[i]);
        }
       for(int j=n-1;j>=0;j--){
            if(j==n-1) suffMax[j]=height[j];
            else suffMax[j]=max(suffMax[j+1],height[j]);
        }
        int trapped=0;
        for(int i=0;i<n;i++){
            if(height[i]<prefMax[i] && height[i]<suffMax[i]){
                trapped+=min(prefMax[i],suffMax[i])-height[i];
            }
        }
        return trapped;
    }
};
// This is the most optimal solution with O(n) Time and O(1) space
// I think this is similar to max water container problem
class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int leftMax=height[0];
        int rightMax=height[j];
        int trapped=0;
        while(i<=j){
            if(leftMax<height[i]) leftMax=height[i];
            if(rightMax<height[j]) rightMax=height[j];
            
            if(height[i]<=height[j]){
                if(height[i]<leftMax && height[i]<rightMax){
                    trapped+=min(leftMax,rightMax)-height[i];
                }
                i++;
            }
            else {
                if(height[j]<leftMax && height[j]<rightMax){
                    trapped+=min(leftMax,rightMax)-height[j];
                }          
                j--;
            }

        }
        return trapped;
    }
};

// This was given in striver 
// Same as above but we aren't 
int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) { // See the difference only checking with leftmax 
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {  // Only with right max
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}

// This is the actual stack based solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        stack<int> st; // store indices of bars, decreasing heights
        int trapped = 0;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break; // no left boundary
                int left = st.top();
                int width = i - left - 1;
                int boundedHeight = min(height[left], height[i]) - height[top];
                if (boundedHeight > 0) trapped += width * boundedHeight;
            }
            st.push(i);
        }
        return trapped;
    }
};
