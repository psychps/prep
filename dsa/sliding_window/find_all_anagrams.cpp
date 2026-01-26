// Pattern: Fixed Sliding Window + Frequency Map
// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n) return {};

        vector<int> pCount(26, 0), sCount(26, 0);
        for (int i = 0; i < m; i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        int match = 0;
        for (int i = 0; i < 26; i++) {
            if (pCount[i] == sCount[i]) match++;
        }

        vector<int> res;
        if (match == 26) res.push_back(0);

        int l = 0;
        for (int r = m; r < n; r++) {
            int c = s[l] - 'a';
            if (sCount[c] == pCount[c]) match--;
            sCount[c]--;
            l++;
            if (sCount[c] == pCount[c]) match++;

            c = s[r] - 'a';
            if (sCount[c] == pCount[c]) match--;
            sCount[c]++;
            if (sCount[c] == pCount[c]) match++;

            if (match == 26) res.push_back(l);
        }

        return res;
    }
};