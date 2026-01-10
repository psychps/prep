class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> duplicate;
        int L = 0;
        for (int R = 0; R < nums.size(); R++) {
            if (R - L > k) {
                duplicate.erase(nums[L]);
                L++;
            }
            if (duplicate.find(nums[R]) != duplicate.end()) {
                return true;
            }
            duplicate.insert(nums[R]);
        }
        return false;
    }
};