// Pattern: Sliding Window (Variable size)
// Time: O(n)
// Space: O(k)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> string_map;
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            if (string_map.find(s[r]) != string_map.end()) {
                l = max(string_map[s[r]] + 1, l);
            }
            string_map[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};