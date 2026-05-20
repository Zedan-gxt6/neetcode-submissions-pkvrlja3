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
    int mymax(vector<int> arr){
        int maxi=INT_MIN;
        for(int i:arr) maxi=max(maxi,i);
        return maxi;
    }
    int helper(TreeNode* root,int* ans){
        if(!root) return -1001;
        int a=root->val;
        int b=helper(root->left,ans);
        int c=helper(root->right,ans);
        (*ans)=mymax({a+b+c,b,c,(*ans)});
        return mymax({a,a+b,a+c});
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int r=helper(root,&ans);
        return max(ans,r);
    }
};
