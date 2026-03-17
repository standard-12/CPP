#include<bits/stdc++.h>
using namespace std;

// This is the optimal solution using dutch national flag algortihm;
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int zero=0;
        int one=0;
        int two=n-1;
        int i=0;
        while(i<=two){
            if(arr[i]==0) {
                swap(arr[i],arr[zero]);
                zero++;
                one++;
                i++;
            }
            else if(arr[i]==1){
                swap(arr[i],arr[one]);
                one++;
                i++;
            }
            else {
                swap(arr[i],arr[two]);
                two--;
            }
        }
    }
};