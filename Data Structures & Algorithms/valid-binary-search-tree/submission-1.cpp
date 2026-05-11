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
        if(!root) return {1,INT_MAX,INT_MIN};

        vector<int> l = validBst(root->left);
        vector<int> r = validBst(root->right);

        if(l[0] && r[0]){
            if(root->val>l[2] && root->val<r[1]) return {1,min(root->val,l[1]),max(root->val,r[2])};
            else return {0,0,0};
        }
        return {0,0,0};
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans= validBst(root);
        return ans[0]==1;
    }
};
