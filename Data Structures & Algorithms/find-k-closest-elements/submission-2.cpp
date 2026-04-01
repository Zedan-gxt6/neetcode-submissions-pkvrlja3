class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n=nums.size();
        int a=0,b=k-1;
        int sum=0;
        for(int i=a;i<=b;i++){
            sum+=(abs(x-nums[i]));
        }
        int ansa=a,ansb=b;
        vector<int> ans;
        while(b+1<n){
            int left=abs(x-nums[a]);
            int right=abs(x-nums[b+1]);
            if(sum-left+right<sum){
               ansa=a+1; ansb=b+1;
            }
             a++; b++;
        }
        for(int i=ansa;i<=ansb;i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};