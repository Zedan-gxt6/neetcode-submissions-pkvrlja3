class Solution {
public:

    vector<int> subvect(vector<int> v,int i,int j){
        return vector<int>(v.begin()+i , v.begin()+j+1);
    }

    void permt(vector<int> v, vector<int> &ans, vector<vector<int>> &finalans){
        int n = v.size();

        if(n == 0){
            finalans.push_back(ans);
            return;
        }

        for(int i=0;i<n;i++){

            ans.push_back(v[i]);

            vector<int> newv;

            if(i==0)
                newv = subvect(v,1,n-1);
            else if(i==n-1)
                newv = subvect(v,0,n-2);
            else{
                vector<int> left = subvect(v,0,i-1);
                vector<int> right = subvect(v,i+1,n-1);

                newv = left;
                newv.insert(newv.end(), right.begin(), right.end());
            }

            permt(newv, ans, finalans);

            ans.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> finalans;
        vector<int> ans;

        permt(nums, ans, finalans);

        return finalans;
    }
};