class Solution {
public:
    vector<int> helper(vector<int>& digits,int i){
        if(i==0){
            if(digits[i]==9){
                digits[i]=0;
                vector<int> arr;
                arr.push_back(1);
                for(int i:digits) arr.push_back(i);
                return arr;
            }
            digits[i]++;
            return digits;
        }
        if(digits[i]==9){
            digits[i]=0;
            return helper(digits,i-1);
        } 
        digits[i]++;
        return digits;
    }
    vector<int> plusOne(vector<int>& digits) {
        return helper(digits,digits.size()-1);
    }
};
