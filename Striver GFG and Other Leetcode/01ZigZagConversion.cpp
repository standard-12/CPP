#include<bits/stdc++.h>
using namespace std;

// I could solve this on my own 
// I used the pattern in distance with d1,d2
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        int dist=(numRows-1)*2;
        int n=s.size();
        string ans;
        int d1=dist;
        int d2=0;
        ans.push_back(s[0]);
        for(int i=0;i<numRows;i++){
            int j=i;
            while(j<n){
                if(d2!=0) ans.push_back(s[j]);
                j=j+d1;
                if(j<n && d1!=0) ans.push_back(s[j]);
                j=j+d2;
            }
            d1=d1-2;
            d2=d2+2;
        }
        return ans;
    }
};

// There is nice O(n) space solution
// Which uses a vector<string> and inserts the char in its own row 
// Uses dir to change direction of j like if dir is 1 then it means j is incresaing (i.e down direction)
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string>v(numRows, ""); 
        int j = 0, dir = -1;
        for(int i = 0; i < s.length(); i++)
        {
        if(j == numRows - 1 || j == 0) dir *= (-1);  
        v[j] += s[i];
        if(dir == 1) j++;
        else j--;
        }

        string res;
        for(auto &it : v) res += it; 
        return res;
    }
};

// This is another solution which is based on formula
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        string result;
        int cycleLen = 2 * numRows - 2;

        for (int row = 0; row < numRows; row++) {
            for (int j = row; j < s.size(); j += cycleLen) {
                result.push_back(s[j]);

                // add the diagonal element (only for middle rows)
                int diag = j + cycleLen - 2 * row;   // See explanation of the formula below
                if (row != 0 && row != numRows - 1 && diag < s.size()) {
                    result.push_back(s[diag]);
                }
            }
        }

        return result;
    }
};
// So we add cyclelen to j which is full cycle i.e if j was in 1 it will go to 7
// Then we subtract 2*row i.e it is in row1 so 2*1 so it comes to 5 from 7

// Row 0: 0       6       12 ...
// Row 1: 1    5  7    11 13 ...
// Row 2: 2  4    8  10    ...
// Row 3: 3       9       ...
