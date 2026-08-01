class Solution {
public:
    void Permutations(int curr,int n,
        vector<int> &nums,
        vector<int> &currPermutation,
        vector<vector<int>> &allPermutations
    ){
        if(curr==n){
            allPermutations.push_back(currPermutation);
            return;
        }
        for(int i=curr;i<n;i++){
            swap(nums[curr],nums[i]);
            currPermutation.push_back(nums[curr]);

            Permutations(curr+1,n,nums,currPermutation,allPermutations);

            swap(nums[curr],nums[i]);
            currPermutation.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> currPermutation;
        vector<vector<int>> allPermutations;
        Permutations(0,n,nums,currPermutation,allPermutations);
        return allPermutations;
    }
};
