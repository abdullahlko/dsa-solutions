class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0, left = 0;
        unordered_set<char> charSet;

        for (int right = 0; right < n; right++) {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            res = max(res, right - left + 1);
        }

        return res;
    }
};

    // TC: O(n)
    // SC: O(min(n, 26))