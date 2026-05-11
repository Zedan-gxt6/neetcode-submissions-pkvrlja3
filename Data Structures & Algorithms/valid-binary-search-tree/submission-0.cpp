/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> validBst(TreeNode* root){
        if(!root) return {1,1001,-1001};

        vector<int> l = validBst(root->left);
        vector<int> r = validBst(root->right);

        if(l[0] && r[0]){
            if(root->val>l[2] && root->val<r[1]) return {1,l[1]==1001?root->val:l[1],r[2]==-1001?root->val:r[2]};
            else return {0,0,0};
        }
        return {0,0,0};
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans= validBst(root);
        return ans[0]==1;
    }
};
