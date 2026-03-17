#include<bits/stdc++.h>
using namespace std;
// this was my solution and it works but here i am doing end-beg==1 which is not necessary this can be done without that as shown below
// basically i couldnt handle the case when there is only 2 elements (either it was going on infinite loop or returning wrong answer so i used 
// this end-beg==1 trick)
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int beg=1;
        int end=x;
        while(beg<end){
            cout<<beg<<" "<<end<<endl;
            int mid=beg+(end-beg)/2;

            if(end-beg==1) return (1LL*end*end<=(long long)x)? end:beg;
            if(1LL* mid*mid==(long long)x)
            return mid;
            else if(1LL*mid*mid<(long long)x){
                beg=mid;
            }
            else {
                end=mid-1;
            }
        }
        return beg;
    }
};
//this is optimal solution actually i had thought we can't use beg<=end or low<=high (because i thought beg should be returned and when there is only
//two elements left at the end beg will be updated to mid+1 ) so i used beg<end but we can use this normal approach and return 'end'; 

int floorSqrt(int n) {
    int low = 1, high = n;
    //Binary search on the answers:
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            //eliminate the left half:
            low = mid + 1;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

// This is for n th root problem
class Solution2 {
public:
    int nthRoot(int n, int m) {
        int beg = 1; 
        int end = m; // i had done end=m/n chatGPT said it is unneccessary and risky but mine worked
        
        while (beg <= end) {
            long long mid = beg + (end - beg) / 2;
            long long val = 1;
            
            // compute mid^n safely because when computing powers of large numbers overflow might happen
            for (int i = 0; i < n; i++) {
                val *= mid;
                if (val > m) break;
            }
            
            if (val == m) return mid;   // exact root
            else if (val > m) end = mid - 1;
            else beg = mid + 1;
        }
        
        return -1; // no exact integer root
    }
};


int main(){
    Solution S=Solution();
    int x=9801;
    cout<<S.mySqrt(x);
}