class Solution {
public:
    void sub(vector<int>& nums,int i,int j,vector<int> &ans,vector<vector<int>> &final){
         if(i>j){
            final.push_back(ans);
            return;
        }
       sub(nums,i+1,j,ans,final);
       ans.push_back(nums[i]);
       sub(nums,i+1,j,ans,final);
       ans.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> final;
         vector<int> ans;
         sub(nums,0,nums.size()-1,ans,final);
         return final;
    }
};
