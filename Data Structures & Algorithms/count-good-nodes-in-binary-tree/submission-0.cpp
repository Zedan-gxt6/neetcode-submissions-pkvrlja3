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
    void helper(TreeNode* root,int max,int* count){
        if(!root) return;
        if(root->val>=max){ (*count)++; max=root->val;}
        helper(root->right,max,count);
        helper(root->left,max,count);
    }
    int goodNodes(TreeNode* root) {
        int count=0,max=INT_MIN;
        helper(root,max,&count);
        return count;
    }
};
