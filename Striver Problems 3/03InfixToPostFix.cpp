#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string infixToPostfix(const string& s) {
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
                       (isRightAssociative(c) ? (prec(c) < prec(st.top()))
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

        return ans;
    }

private:
    static bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    static bool isRightAssociative(char ch) {
        return ch == '^';
    }

    static int prec(char ch) {
        switch (ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case '(' : return 0;
        default: return -1;
        }
    }
};
