class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int curr=1;
        unordered_set<int> seen;
        for(int num:nums){
            if(num>0) seen.insert(num);
            while(seen.count(curr)) curr++;
        }
        return curr;
    }
};