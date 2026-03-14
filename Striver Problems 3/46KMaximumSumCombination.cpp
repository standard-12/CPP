#include<bits/stdc++.h>
using namespace std;

// I couldn't come up with the solution for this 
// This is a nice solution and here i learned many thing About C++ internals (i will try to explain it in next file)
class Solution {
  public:
    class Node {
        public:
                int sum,i,j;
                
                Node(int sum,int i,int j){
                    this->sum=sum;
                    this->i=i;
                    this->j=j;
                }
    };
    
    class index{
        public:
            int i;
            int j;
            
            index(int i,int j){
                this->i=i;
                this->j=j;
            }
        bool operator==(const index& a) const noexcept{
            return (i==a.i && j==a.j);
        }
    };
    
    struct Indexhash{
        size_t operator()(const index& a)const noexcept{
            return ((size_t(a.i)<<32) ^ size_t(a.j));
        }
    };
    struct comp{
        bool operator()(const Node& a,const Node& b){
            return a.sum<b.sum;
        }
    };
    
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        
        priority_queue<Node,vector<Node>,comp> pq;
        unordered_set<index,Indexhash> st;
        
        pq.push(Node(a[0]+b[0],0,0));
        st.insert(index(0,0));
        
        vector<int> ans;
        
        while(k>0 && !pq.empty()){
            
            Node temp=pq.top();
            pq.pop();
            int sum=temp.sum;
            int i=temp.i;
            int j=temp.j;
            
            ans.push_back(sum);
            
            // using i,j of the old node we get the next nodes 
            if( i+1 < a.size() && !st.count({i+1,j})){  
                pq.push(Node(a[i+1]+b[j],i+1,j));
                st.insert(index(i+1,j));
            } 
            
            if( j+1 < b.size() && !st.count({i,j+1})){
                pq.push(Node(a[i]+b[j+1],i,j+1));
                st.insert(index(i,j+1));
            }
            k--;
        }
        return ans;
    }
};