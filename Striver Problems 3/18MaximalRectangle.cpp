#include<bits/stdc++.h>
using namespace std;

// Very nice question simulating the histogram by taking each row as the base 
// Uses prefixSum logic with Histogram Question
// Remember to set PrefixSum to 0 when we encounter a zero in base ( i.e in any row)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> prefixSum(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') prefixSum[j]+=1;
                else prefixSum[j]=0;
            }
            stack<int> st;
            for(int k=0;k<m;k++){
                while(!st.empty() && prefixSum[st.top()]>=prefixSum[k]){
                    int val=prefixSum[st.top()];
                    int nse=k; // Be careful index name is k not i
                    st.pop();
                    int pse=st.empty()? -1:st.top();
                    int width=nse-pse-1;
                    maxi=max(maxi,val*width);
                }
                st.push(k);
            }
            while(!st.empty()){
                int val=prefixSum[st.top()];
                int nse=m;
                st.pop();
                int pse=st.empty()? -1:st.top();
                int width=nse-pse-1;
                maxi=max(maxi,val*width);
            }
        }
        return maxi;
    }
};