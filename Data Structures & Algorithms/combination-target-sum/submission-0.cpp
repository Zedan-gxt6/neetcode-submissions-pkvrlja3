class Solution {
public:
    void comb(vector<int>& nums,int i,int j,int target,vector<int> &ans,vector<vector<int>> &final){
         if(target<0 || i>j){
            return;
        }
        if(target==0){
            final.push_back(ans);
            return;
        }
       comb(nums,i+1,j,target,ans,final);
       ans.push_back(nums[i]);
       comb(nums,i,j,target-nums[i],ans,final);
       ans.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
         vector<vector<int>> final;
         vector<int> ans;
         comb(nums,0,nums.size()-1,target,ans,final);
         return final;
    }
};
