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
    void helper(TreeNode* root,int d,int* cover,vector<int> &ans){
        if(root==NULL) return;
        if(d>*cover){
            ans.push_back(root->val);
            (*cover)++;
        }
        helper(root->right,d+1,cover,ans);
        helper(root->left,d+1,cover,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        int cover=0,depth=1;
        vector<int> ans;
        helper(root,depth,&cover,ans);
        return ans;
    }
};
