#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
#include<chrono>
#include <cmath>
using namespace std;

int middle_school_algo(int m,int n) {
    vector<int> v1;
    vector<int> v2;
    int gcd=0;

    for(int i=1;i*i<m;i++){
        if(m % i == 0){
            v1.push_back(i);
            if(m/i != i){
                v1.push_back(m/i);
            }
        }
    }
    for(int i=1;i*i<n;i++){
        if(n % i == 0){
            v1.push_back(i);
            if(n/i != i){
                v1.push_back(n/i);
            }
        }
    }
    for(int d : v1 ) {
        if(find(v2.begin(),v2.end(),d) != v2.end()){
            gcd=max(d,gcd);
        }
    }
    return gcd;
}

int eculedian (int m,int n) {
    if(n==0) return m;
    return eculedian(n,m%n);
}

int consecutive_integeres_algo(int m,int n){
    int gcd=min(m,n);
    while(gcd>0){
        if(m%gcd==0 && n%gcd==0)
            return gcd;
        gcd--;
    }
    return 1;
}

double measure_time(int (*func)(int,int),int m ,int n) {
    auto start = std::chrono::high_resolution_clock::now();
    int GCD=func(m,n);
    cout<<"GCD is : "<<GCD<<endl;
    auto end= std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return elapsed.count();
}

int main() {
    int m = 123456789, n = 987654321;
    double time_taken;

    cout << " Middle School GCD (Average Speed)\n";
    time_taken = measure_time(middle_school_algo, m, n);
    cout << "Time Taken: " << time_taken << " micro sec\n\n";
}