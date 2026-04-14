#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s) {

            // push opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }

            // if closing bracket comes but stack is empty
            if(st.empty()) return false;

            char top = st.top();

            // check mismatch
            if(ch == ')' && top != '(') return false;
            if(ch == '}' && top != '{') return false;
            if(ch == ']' && top != '[') return false;

            // valid match
            st.pop();
        }

        return st.empty();
    }
};