class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary(0,nums.size()-1, nums, target);
    }
    int binary(int left, int right, vector<int>& nums, int target){
        if(left>right){
            return -1;
    }
        int mid = left + (right-left)/2;
        if (nums[mid]==target){
            return mid;
        }
        if(nums[mid]<target){
             return binary(mid+1, right, nums, target);
        }
        else{
            return binary(left, mid-1, nums, target);
        }
    }
};