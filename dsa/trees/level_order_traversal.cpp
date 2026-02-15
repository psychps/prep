// Pattern: Tree BFS
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> lvl;
            int size = q.size();

            for(int i = q.size(); i>0;i--){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    lvl.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (!lvl.empty()) {
                res.push_back(lvl);
            }
        }
        return res;
    }
};