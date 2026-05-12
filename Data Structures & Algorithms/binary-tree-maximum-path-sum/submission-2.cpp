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
    int helper(TreeNode* root,int* glmax){
        if(!root) return 0;

        int a=root->val;
        int b=helper(root->left,glmax);
        int c=helper(root->right,glmax);

        if(!root->left && !root->right){
            (*glmax)=max(*glmax,a);
            return a;
        }
        if(!root->left){
            (*glmax)=mymax({*glmax,c});
            return mymax({a,a+c});
        }
        if(!root->right){
            (*glmax)=mymax({*glmax,b});
            return mymax({a,a+b});
        }
        //Both children present..
        (*glmax)=mymax({*glmax,b,c,a+b+c});
        return mymax({a,a+b,a+c});
    }
    int maxPathSum(TreeNode* root) {
        int globalMax=INT_MIN;
        int ans=helper(root,&globalMax);
        return max(globalMax,ans);
    }
};
