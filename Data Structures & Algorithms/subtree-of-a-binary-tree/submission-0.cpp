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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val==q->val){
            if(isSameTree(p->left,q->left)){
                return isSameTree(p->right,q->right);
            }
            return false;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val==subRoot->val){
            if(isSameTree(root,subRoot)) return true;
            if(isSubtree(root->left,subRoot)) return true;
            return isSubtree(root->right,subRoot);
        }
    }
};
