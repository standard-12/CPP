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

bool isPrime(int n) {
    // 1 and negative numbers are not prime
    if (n <= 1) return false;
    
    // 2 is the only even prime number
    if (n == 2) return true;
    
    // Exclude all other even numbers
    if (n % 2 == 0) return false;
    
    // Check odd factors up to the square root of n
    // Using i * i <= n avoids the overhead of the sqrt() function
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false; // Found a factor, so it's not prime
        }
    }
    
    return true; // No factors found, it is prime
}