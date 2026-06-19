class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int top = 0;
        int vmid;
        while (row > top) {
            vmid = top + (row - top) / 2;
            if (matrix[vmid][col - 1] == target) return true;
            else if (matrix[vmid][col - 1] < target) top = vmid + 1;
            else row = vmid;
        }
        if (top >= matrix.size()) return false;
        int hmid = 0;
        while (col > left) {
            hmid = left + (col - left) / 2;
            if (matrix[top][hmid] == target) return true;
            else if (matrix[top][hmid] < target) left = hmid + 1;
            else col = hmid;
        }
        return false;
    }
};