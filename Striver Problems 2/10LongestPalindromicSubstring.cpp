#include<bits/stdc++.h>
using namespace std;
// This is a very very imp problem this can be solved using O(n) time and O(n) space using Manchers Algorithm which is very difficult and not needed
// for our level now

// Another approach is using recursion i.e DP with memoization which is not discussed here 
// Here main focus is on EXPAND AROUND CENTRE approach of time complexity O(n^2) and Space Complexity O(1)

// This was my first brute force solution which is of O(n^3)
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0;
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                if(s[i]==s[j]){
                    bool b=isPalindrome(s,i,j);
                    int len=j-i+1;
                    if(b && len>maxlen){
                        maxlen=len;
                        ans=s.substr(i,len);
                        break;
                    }
                }
            }
        }
        return ans;
    }

    bool isPalindrome(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

// This was my solution after seeing a video but i just saw the concept and implemented it on my own
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0;
        string ans;
        for(int i=0;i<n;i++){
            int len1=Palin(s,i,i); // for odd length palindromes
            int len2=Palin(s,i,i+1); // for even length palindormes
            int local_max=max(len1,len2);
            if(local_max>maxlen){
                maxlen=local_max;
                int ij=local_max==len1? i-(len1/2):i-((len2/2)-1); // finding starting index of substring based on if it was taken form len1 or len2
                ans=s.substr(ij,maxlen);
            }
        }
        return ans;
    }
    int Palin(string& s,int i,int j){  // i smartly used same function for both odd and even without any help
        int n=s.size();
        int left=i-1;
        int right=j+1;
        int len;
        if(i==j) len=1;
        else if(s[i]==s[j]) len=2;
        else return 0; 

        while(left>=0 && right<n){
            if(s[left]!=s[right]) return len;
            else len=len+2;
            left--;
            right++;
        }
        return len;
    }
};

// same code but with better readability is given below by chatgpt
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxlen = 1;

        for (int i = 0; i < n; i++) {
            int len1 = expand(s, i, i);     // odd length
            int len2 = expand(s, i, i + 1); // even length
            int len = max(len1, len2);

            if (len > maxlen) {
                maxlen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxlen);
    }

private:
    int expand(const string& s, int left, int right) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // length of palindrome
    }
};
