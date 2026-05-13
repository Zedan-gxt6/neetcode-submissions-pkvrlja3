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
    TreeNode* helper(TreeNode* root,int p,int q,TreeNode** ans){
        if(!root) return NULL;
        
        TreeNode* l=helper(root->left,p,q,ans);
        TreeNode* r=helper(root->right,p,q,ans);

        if(l && r) {(*ans)=root; return root;}
        if(l || r){
            if(root->val==p || root->val==q){
                (*ans)=root;
            }
            return root;
        } 
        if(root->val==p || root->val==q){
            return root;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        helper(root,p->val,q->val,&ans);
        return ans;
    }
};
