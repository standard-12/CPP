#include<bits/stdc++.h>
using namespace std;
// First we should reverse the given expression (remember to reverse the brackets separatel (see the function below))
// Then Apply Postfix Conversion with one main change (see line 42)
// Then Reverse the answer that is our prefix expression

class Solution {
  public:
    string infixToPrefix(string &s) {
        // Write your code here
        rev(s);
        stack<char> st;
        string ans;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            char c = s[i];

            // skip whitespace
            if (isspace((unsigned char)c)) continue;

            // operand: letters or digits
            if (isalnum((unsigned char)c)) {
                ans.push_back(c);
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                // pop until '(' or empty
                while (!st.empty() && st.top() != '(') {
                    ans.push_back(st.top());
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') st.pop(); // safe pop
                // else: mismatched ')', we just ignore (could throw or handle error)
            }
            else if (isOperator(c)) {
                // '^' is right-associative: pop while prec(curr) < prec(top)
                // other ops are left-associative: pop while prec(curr) <= prec(top)
                while (!st.empty() && st.top() != '(' &&
                       (!isRightAssociative(c) ? (prec(c) < prec(st.top())) // See this '!' is the main change 
                                              : (prec(c) <= prec(st.top())))) {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }
            // else: unknown token -> ignore or handle error
        }

        while (!st.empty()) {
            if (st.top() != '(' && st.top() != ')') ans.push_back(st.top());
            st.pop();
        }
        rev(ans);
        return ans;
        
        
    }
    
    void rev(string& s){
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            if(s[i]=='(') s[i]=')';
            else if(s[i]==')') s[i]='(';
            
            if(s[j]=='(') s[j]=')';
            else if(s[j]==')') s[j]='(';
            
            swap(s[i],s[j]);
            i++;
            j--;
        }
        if (i == j) { // If string is of odd length we should flip the ( to ) & ) to ( 
            if (s[i] == '(') s[i] = ')';
            else if (s[i] == ')') s[i] = '(';
        }   
        return;
    }
   bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
 bool isRightAssociative(char ch) {
        return ch == '^';
    }

   int prec(char ch) {
        switch (ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case '(' : return 0;
        default: return -1;
        }
    }
};