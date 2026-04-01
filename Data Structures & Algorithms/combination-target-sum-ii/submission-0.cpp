class Solution {
public:
    void comb(vector<int>& nums, int i, int j, int target,
              vector<int> &ans, vector<vector<int>> &final,
              unordered_map<int,int> &m) {

        if(target == 0){
            final.push_back(ans);
            return;
        }

        if(i > j || target < 0) return;

        // skip current
        comb(nums, i+1, j, target, ans, final, m);

        // take 1..freq times
        for(int count = 1; count <= m[nums[i]]; count++){
            for(int c = 0; c < count; c++){
                ans.push_back(nums[i]);
            }
            comb(nums, i+1, j, target - count * nums[i], ans, final, m);
            for(int c = 0; c < count; c++){
                ans.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        unordered_map<int,int> m;
        vector<int> newarr;

        for(int x : nums){
            if(!m.count(x)){
                newarr.push_back(x);
                m[x] = 1;
            } else {
                m[x]++;
            }
        }

        //sort(newarr.begin(), newarr.end()); // 🔥 IMPORTANT

        vector<vector<int>> final;
        vector<int> ans;

        comb(newarr, 0, newarr.size()-1, target, ans, final, m);

        return final;
    }
};