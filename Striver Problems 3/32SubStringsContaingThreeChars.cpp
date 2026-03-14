#include<bits/stdc++.h>
using namespace std;

// I solved this on my own hurray
// Idea is if a substring satisfies the condition all substrings staring with that satisfy the condition
// TIme Complexity O(2n) Space Complexity O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int cnta=0,cntb=0,cntc=0;
        int i=0,j=0;
        int ans=0;

        while(j<n){  
            if(s[j]=='a') cnta++;
            else if(s[j]=='b') cntb++;
            else cntc++;

            while(cnta>0 && cntb>0 && cntc>0){
                ans+=n-j; // All chars to the right of the j
                if(s[i]=='a') cnta--;
                else if(s[i]=='b') cntb--;
                else cntc--;
                i++;
            }
            j++;
            
        }
        return ans;
    }
};

// E.g in abcabc if abc satisfies then abc,abca,abcab,abcabc satisy (i.e 4 == n-j (6-2))
// Then we move i to find next window 
// that is bca satisifes implies bca,bcab,bcac satisfy (i.e 3 == n-j (6-3))
// And So on

// The above solution is very nice and enough but striver gave a more optimal solution

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int inda=-1,indb=-1,indc=-1; //Stores the latest index;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a') inda=i;
            else if(s[i]=='b') indb=i;
            else indc=i;

            if(inda==-1 || indb==-1 || indc==-1) continue;

            int mini=min(inda,min(indb,indc));
            count+=mini+1;
        }
        return count;

    }
};