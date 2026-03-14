#include<iostream>
#include<vector>
using namespace std;
void knapscak(const vector<int>& weights,const vector<int>& profits,int capacity) {
    int n=weights.size();
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));

    for(int i=1;i<=n;i++){
        for(int w=1;w<=capacity;++w){
            if(weights[i-1] <= w){
                dp[i][w] = max(dp[i-1][w],profits[i-1]+dp[i-1][w-weights[i-1]]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }

    cout<<"Maximum Profit :"<<dp[n][capacity]<<endl;

    cout<<"Selected items :";
    int w = capacity;
    for(int i=n;i>0 && w>0; --i){
        if(dp[i][w] != dp[i-1][w]){
            cout<<"Item "<<i<<" ";
            w-=weights[i-1];
        }
    }
}

int main(){
    vector<int> weights={2,3,4,5};
    vector<int> profits={10,20,50,60};
    int capacity=8;
    knapscak(weights,profits,capacity);
    return 0;
}