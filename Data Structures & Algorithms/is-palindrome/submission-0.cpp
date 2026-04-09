class Solution {
public:
    string reverseStr(string& s) {
        string rev = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            rev += s[i];
        }
        return rev;
    }

    bool isPalindrome(string s) {
        string newStr = "";

        for (char c : s) {
            if ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9')) {

                newStr += tolower(c);
            }
        }

        return reverseStr(newStr) == newStr;
    }
};