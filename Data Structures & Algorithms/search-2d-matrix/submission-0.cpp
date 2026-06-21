class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int x,y;
        int l=0,r=m*n-1,mid,i,j;
        while(l<=r){
            mid=l+(r-l)/2;
            i=mid/n,j=mid%n;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};
