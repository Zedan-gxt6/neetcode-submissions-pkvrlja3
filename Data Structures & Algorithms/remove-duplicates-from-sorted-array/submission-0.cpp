class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int a=1,b=1;
        while(b<n){
            if(nums[b]==nums[b-1]) b++;
            else{
                nums[a]=nums[b];
                a++;
                b++;
            }
        }
        return a;
    }
};