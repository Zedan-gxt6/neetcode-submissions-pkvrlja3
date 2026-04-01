class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,sum=0,min=n+1;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                if(j-i+1<min) min=j-i+1;
                if(i==j) return 1;
                sum-=nums[i++];
            }
            j++;
        }
        if(min==n+1) return 0;
        return min;
    }
};