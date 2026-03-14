#include<bits/stdc++.h>
using namespace std;

// This i couldn't solve on my own especially about overlapping solutions 
// The optimal solution is using dp
// This is O(n1*n2) solution
class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int start = -1, minLen = INT_MAX;
        int i = 0;
        
        while(i < n1) {
            int p = 0;  // pointer for s2
            int j = i;  // start searching from position i
            
            // Try to match all characters of s2
            while(j < n1 && p < n2) {
                if(s1[j] == s2[p]) p++;
                j++;
            }
            
            // If we matched all of s2
            if(p == n2) {
                // j-1 is the end of the match, now find the actual start
                int end = j - 1;
                p--;
                
                // Backtrack to find the tightest window
                while(p >= 0) {
                    if(s1[end] == s2[p]) p--;
                    end--;
                }
                end++;  // end now points to the start of the window
                
                // Update if this window is smaller
                if(j - end < minLen) {
                    minLen = j - end;
                    start = end;
                }
                
                // Continue from the next position after current start
                i = end + 1;
            } else {
                break;  // Can't find any more matches
            }
        }
        
        return start == -1 ? "" : s1.substr(start, minLen);
    }
};