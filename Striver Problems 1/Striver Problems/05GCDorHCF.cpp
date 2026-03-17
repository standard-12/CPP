#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int n1,int n2);

int main() {
    int n1,n2;
    cout<<"Enter 2 numbers : ";
    cin>>n1>>n2;

    int GCD = gcd (n1,n2);
    cout<<"GCD is :"<<GCD;
}

int gcd(int n1,int n2){
    if(n2==0) return n1;
    return gcd(n2,n1%n2);
}
 
// Without recursin 
/* while(a>0 && b>0){
    if a<b a=a%b;
    else b=b%a;
}
    if(a==0) cout<<b;
    else cout<<a;
*/