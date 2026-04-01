class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(i<=maxi){
                maxi=max(maxi,i+nums[i]);
                if(maxi>=n-1) return true;
            }
            else return false;
        }
        return true;
    }
};
