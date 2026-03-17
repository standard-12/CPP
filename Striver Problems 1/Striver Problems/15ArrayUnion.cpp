#include<iostream>
#include<vector>
using namespace std;
// Assuming a and b are sorted arrays 
vector<int> unionofarray(vector<int>& a,vector<int>& b){
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if( ans.size()==0 || ans.back()!=a[i]){
                ans.push_back(a[i]);
            }
            i++;
        }
        else {
            if( ans.size()==0 || ans.back()!=b[j] ){
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if( ans.size()==0 || ans.back()!=a[i] ){
            ans.push_back(a[i]);
        }
        i++;
    }
    while(j<n2){
        if( ans.size()==0 || ans.back()!=b[j] ){ // Should check if ans.size()==0 beofre using back() otherwise its a error
            ans.push_back(b[j]);
        }
        j++;        
    }
    return ans;
}

int main(){
    int n; // Enter size
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> ans=unionofarray(a,b);
    for(auto it:ans) cout<<it<<" ";
    return 0;
}