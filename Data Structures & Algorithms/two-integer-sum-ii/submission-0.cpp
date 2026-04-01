class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n=numbers.size();
        int a=0,b=n-1;
        while(a<b){
            int num=numbers[a]+numbers[b];
            if(num>target) b--;
            else if(num<target) a++;
            else {
                ans.push_back(a+1);
                ans.push_back(b+1);
                return ans;
            }
        }
        return ans;
    }
};
