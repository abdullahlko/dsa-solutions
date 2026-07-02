class Solution {
public:
    void solve(int open, int close, string& current, vector<string>& ans) {

        // Base case
        if (open == 0 && close == 0) {
            ans.push_back(current);
            return;
        }

        // Place an opening parenthesis
        if (open > 0) {
            current.push_back('(');

            solve(open - 1, close, current, ans);

            current.pop_back(); // Backtrack
        }

        // Place a closing parenthesis
        if (close > open) {
            current.push_back(')');

            solve(open, close - 1, current, ans);

            current.pop_back(); // Backtrack
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