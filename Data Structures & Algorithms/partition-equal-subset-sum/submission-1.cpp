class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int x : nums) total += x;
        if(total % 2 != 0) return false;

        int target = total / 2;

        unordered_set<int> s;
        s.insert(0);

        for(int x : nums){
            unordered_set<int> next = s;
            for(int cur : s){
                int ns = cur + x;
                if(ns == target) return true;
                if(ns < target) next.insert(ns);
            }
            s = next;
        }
        return false;
    }
};
