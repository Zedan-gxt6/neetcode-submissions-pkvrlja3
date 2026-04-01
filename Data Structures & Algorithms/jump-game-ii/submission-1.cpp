class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,n=nums.size(),count=0,maxi=0;
        while(r<n-1){
            maxi=max(maxi,l+nums[l]);
            if(l==r){
                count++;
                r=maxi;
            }
            l++;
        }
        return count;
    }
};
