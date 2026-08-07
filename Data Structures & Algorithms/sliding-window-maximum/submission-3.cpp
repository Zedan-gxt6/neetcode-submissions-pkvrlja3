class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        int l=0,r=1;
        int currMaxIndex=0;
        dq.push_back(0);

        while(r<k){
            int rightIndex=dq.back();
            while(!dq.empty() && nums[rightIndex]<nums[r]){
                dq.pop_back();
                rightIndex=dq.back();
            }
            dq.push_back(r);
            r++;
        } 

        currMaxIndex=dq.front();
        ans.push_back(nums[currMaxIndex]);

        while(r<n){

            while(!dq.empty() && nums[dq.back()]<nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);

            int leftIndex=dq.front();
            if(l==leftIndex) dq.pop_front();
            l++;

            currMaxIndex=dq.front();
            ans.push_back(nums[currMaxIndex]);

            r++;
        }

        return ans;
    }
};
