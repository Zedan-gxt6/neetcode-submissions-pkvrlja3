class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<=n;i++){
            ans^=i;
            if(i<n) ans^=nums[i];
        }
        return ans;
    }
};
