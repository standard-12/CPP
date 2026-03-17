#include<iostream>
#include<vector>
using namespace std;
// Optimal Method Time Complexity O(n1+n2) Space Complexity O(n1+n2)
vector<int> arrayIntersection(vector<int>& a,vector<int>& b){
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n1 && j<n2){
        if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;
                j++;            
        }
        else if(a[i]<b[j]){
            i++;
        }
        else {
            j++;
        }
    }
    return ans;
}
// Brute force method TIme Complexity O(n1*n2) Space Complexity (O(n2))+O(n1+n2)
vector<int> arrayIntersection(vector<int>& a, vector<int>& b) { 
    int n2 = b.size();
    vector<bool> visited(n2, false);  // to mark matched elements in b
    vector<int> ans;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j] && !visited[j]) {
                ans.push_back(a[i]);
                visited[j] = true;  // mark this b[j] as used
                break;              // move to next a[i]
            }
        }
    }

    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> ans=arrayIntersection(a,b);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}