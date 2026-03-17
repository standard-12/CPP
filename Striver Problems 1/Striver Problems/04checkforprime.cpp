#include<iostream>
using namespace std;

int main() {
    cout<<"Enter a number : ";
    int n,count=0;
    cin>>n;

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            count++;
            if(n/i!=i) count++;
        }
    }

    if(count==2) cout<<"Its a prime ";
    else cout<<"Its a non prime";
}