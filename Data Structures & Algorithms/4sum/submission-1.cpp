class Solution {

    void increment(vector<int> &nums,int &i,int &j){
        while(i<j && nums[i+1]==nums[i]) i++;
        i++;
    }

    void decrement(vector<int> &nums,int &i,int &j){
        while(i<j && nums[j-1]==nums[j]) j--;
        j--;
    }

    void twoSum(vector<int>& nums,int n,int start,long long target,
     vector<int> &curr, vector<vector<int>> &ans){

        int i=start,j=n-1;

        while(i<j){
            long long currSum = nums[i]+nums[j];
            if(currSum==target){
                curr.push_back(nums[i]);
                curr.push_back(nums[j]);

                ans.push_back(curr);

                curr.pop_back();
                curr.pop_back();

                increment(nums,i,j);
                decrement(nums,i,j);
            }
            else{
                if(currSum>target) decrement(nums,i,j);
                else increment(nums,i,j);
            }
        }

    }

    void threeSum(vector<int>& nums,int n,int start,long long target,
     vector<int> &curr, vector<vector<int>> &ans){

        for(int i=start;i<=n-3;i++){

            if(i>start && nums[i-1]==nums[i]) continue;

            curr.push_back(nums[i]);
            twoSum(nums,n,i+1,target-nums[i],curr,ans);
            curr.pop_back();
        }
    }

public:
    
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        for(int i=0;i<=n-4;i++){

            if(i>0 && nums[i-1]==nums[i]) continue;

            curr.push_back(nums[i]);
            threeSum(nums,n,i+1,target-nums[i],curr,ans);
            curr.pop_back();
        }

        return ans;
    }
};