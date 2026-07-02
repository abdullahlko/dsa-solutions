class Solution {
public:
    void solve(int open, int close, string current, vector<string>& ans) {

        // Base case
        if (open == 0 && close == 0) {
            ans.push_back(current);
            return;
        }

        // Place an opening parenthesis
        if (open > 0) {
            string temp = current;
            temp.push_back('(');

            solve(open - 1, close, temp, ans);
        }

        // Place a closing parenthesis
        if (close > open) {
            string temp = current;
            temp.push_back(')');

            solve(open, close - 1, temp, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        int open = n;
        int close = n;
        string current = "";

        solve(open, close, current, ans);

        return ans;
    }
};