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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        // a: Root,b:Smaller one,c:Larger one
        int a=root->val;
        int b=p->val<q->val?p->val:q->val;
        int c=b==p->val?q->val:p->val;
        //Check if i am the LCA,if yes return
        if(a>=b && a<=c) return root;
        //Check with BST property for LCA
        if(a<b) return lowestCommonAncestor(root->right,p,q);
        if(a>c) return lowestCommonAncestor(root->left,p,q);
    }
};
