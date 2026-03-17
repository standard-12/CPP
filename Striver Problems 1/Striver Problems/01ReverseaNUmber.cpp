#include<iostream>
#include<stack>
#include<cmath> // For floor() and log10()
using namespace std;

int main(){
    int n;
    cin>>n;
   
    int res=0;    
    int m=floor(log10(abs(n)))+1; // Returns no of digits in n;
    
    
    while(n!=0){
        int k=n%10;
        n=n/10;
        res=res+ceil(k*(pow(10,m-1))); // Ceil to remove precision error
        m--;
        
    }
    cout<<res; 
}

// See notion for the optimal solution