#include<bits/stdc++.h>
using namespace std;

// This was my solution and is the optimal ( i mean see below )
// Time Complexity O(2n) Space Complexity O(1)
// Map can be used for simplicity instead of 2 variables
// Here we can't directly replace a while with if (here we should use map if we want the O(n) solution) and hence space will be O(n) in optimal
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int j=0;
        int type1=-1,type2=-1;
        int cnt1=0,cnt2=0;
        int maxLen=0;
        while(j<n){
            if(type1 == -1 || type1==fruits[j]){
                type1=fruits[j];
                cnt1++;
                maxLen=max(maxLen,j-i+1);
                j++;
            }
            else if(type2 == -1 || type2==fruits[j]){
                type2=fruits[j];
                cnt2++;
                maxLen=max(maxLen,j-i+1);
                j++;
            }
            else {
                while(i<n && cnt1>0 && cnt2>0){
                    if(fruits[i]==type1){
                        cnt1--;
                    }
                    else if(fruits[i]==type2){
                        cnt2--;
                    }
                    i++;
                }
                if(cnt1==0) type1=-1;
                else if(cnt2==0) type2=-1;
            }
        }
        return maxLen;
    }
};


// This is the O(n) solution but striver said space complexity is O(1) but its not actually O(1)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int j=0;
        int maxLen=0;
        unordered_map<int,int> freq;
        while(j<n){
            freq[fruits[j]]++;
            if(freq.size()>2){  // use while loop here to have O(1) space but O(2n) time (i.e like above solution)
                freq[fruits[i]]--;
                if(freq[fruits[i]]==0) freq.erase(fruits[i]);
                i++;
            }
            if(freq.size()<=2) maxLen=max(maxLen,j-i+1);
            j++;
        }      
        return maxLen;
    }
};