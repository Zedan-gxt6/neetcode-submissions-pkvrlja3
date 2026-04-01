class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int a=i+1,b=nums.size()-1;
            
            while(a<b){
                if(nums[a]+nums[b]==(-1*nums[i])){
                    ans.push_back({nums[i],nums[a],nums[b]});
                    while (a < b && nums[a] == nums[a+1]) a++;
                    while (a < b && nums[b] == nums[b-1]) b--;
                    a++; b--;
                }
                else if(nums[a]+nums[b]<(-1*nums[i])) a++;
                else b--;
            }
        }
        return ans;
    }
};