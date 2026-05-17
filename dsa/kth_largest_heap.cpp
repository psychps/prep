class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        make_heap(nums.begin(),nums.end());
        while(k>0){
            pop_heap(nums.begin(),nums.end());
            res = nums.back();
            nums.pop_back();
            k--;
        }
       return res;
    }
};