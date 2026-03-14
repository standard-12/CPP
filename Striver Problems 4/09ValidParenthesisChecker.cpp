#include<bits/stdc++.h>
using namespace std;

// This was my solution But this is not the optimal solution
// And i wasn't sure this would get accepted but it got accepted
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int openCount=0;
        int starCount=0;
        int closeCount=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') openCount++;
            else if(s[i]==')') closeCount++;
            else starCount++;

            if(closeCount>openCount+starCount) return false;
        }

         openCount=0;
         starCount=0;
         closeCount=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(') openCount++;
            else if(s[i]==')') closeCount++;
            else starCount++;

            if(openCount>closeCount+starCount) return false;
        }
        return true;
    }
};

// This is the optimal one pass solution 

class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int min=0,max=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
                if(min<0 && max>=0) min++;
                else if(min<0) return false; 
            }
            else {
                if(min!=0) min--;
                max++;
            }
            i++;
        }
        return min==0;
    }
};