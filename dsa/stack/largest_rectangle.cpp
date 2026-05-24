class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        for (int i = 0; i <= heights.size(); ++i) {
            while (!s.empty() && (i == heights.size() || heights[i] < heights[s.top()])) {
                int idx = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                res = max(res, heights[idx] * (i - left - 1));
            }
            s.push(i);
        }
        return res;
    }
};