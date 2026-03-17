#include<bits/stdc++.h>
using namespace std;

// Same concept as median problem but a minor necessary change otherwise this wont work changes are shown below
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1=a.size();
        int n2=b.size();
          if (k < 1 || k > n1 + n2) return -1;
        if(n1>n2){
            return kthElement(b,a,k);
        }
        // we just cant take beg=0 and end=n1 like before because there it was always half the size here it is not necessary to be half k can be 1 2
        // and k can be more also like if n1=5 and n2=6 we perform bs on n1 but if k is 9 and we take 6 elements from n2 still 2 3 elements
        // should be taken from n1 so we make beg=max(0,k-n2);
        int beg=max(0,k-n2);
        int end=min(n1,k);
        while(beg<=end){
            int mid1=beg+(end-beg)/2;
            int mid2=k-mid1;
            int right1=mid1<n1? a[mid1]:INT_MAX;
            int right2=mid2<n2? b[mid2]:INT_MAX;
            int left1=mid1-1>=0? a[mid1-1]:INT_MIN;
            int left2=mid2-1>=0? b[mid2-1]:INT_MIN;

            if(left1<=right2 && left2<=right1){
                return max(left1,left2);
            }
            else if(left1>right2) end=mid1-1;
            else beg=mid1+1;
        }
        return -1;
    }
};