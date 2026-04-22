#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    // code here
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}
