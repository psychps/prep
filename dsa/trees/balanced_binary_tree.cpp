
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return heightdfs(root)[0]==1;
    }
    vector<int> heightdfs(TreeNode* root){
        if(!root){
            return {1,0};
        }
        vector<int> left = heightdfs(root->left);
        vector<int> right = heightdfs(root->right);
        bool balanced = (left[0] == 1 && right[0] == 1) &&
                        (abs(left[1] - right[1]) <= 1);
        int height = 1 + max(left[1], right[1]);

        return {balanced ? 1 : 0, height};
    }
};