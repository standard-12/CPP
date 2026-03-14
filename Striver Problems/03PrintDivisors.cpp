#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> divisors;
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<"Divisors Are :";
    for(int i=1;i*i<=n;i++) // i*i<=n instead of calling sqrt i<=sqrt(n)
    {
        if(n%i==0){
            divisors.push_back(i);
            cout<<i<<" ";
            if(n/i!=i) {
                divisors.push_back(n/i);
                cout<<n/i<<" ";
            }
        }
    }
    sort(divisors.begin(),divisors.end());
    cout<<"Sorted :";
    for(auto it : divisors) cout<<it<<" ";
    
}