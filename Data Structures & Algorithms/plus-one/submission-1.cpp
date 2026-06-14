class Solution {
public:
    vector<int> helper(vector<int> &digits,int i){
        if(digits[i]==9){
            digits[i]=0;
            if(i-1>=0) return helper(digits,i-1);
            else{
                digits[i]=0;
                vector<int> ans;
                ans.push_back(1);
                for(auto num:digits) ans.push_back(num);
                return ans;
            }
        }
        digits[i]++;
        return digits;
    }
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        return helper(digits,n-1);
    }
};
