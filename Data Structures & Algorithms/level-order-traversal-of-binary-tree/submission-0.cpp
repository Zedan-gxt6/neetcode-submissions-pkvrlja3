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
    void helper(TreeNode* root,int d,vector<vector<int>> &ans,int* l){
        if(!root) return;
        if(d>*l){
            vector<int> arr;
            arr.push_back(root->val);
            ans.push_back(arr);
            (*l)++;
        }
        else ans[d].push_back(root->val);
        helper(root->left,d+1,ans,l);
        helper(root->right,d+1,ans,l);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int l=-1,d=0;
        helper(root,d,ans,&l);
        return ans;
    }
};
