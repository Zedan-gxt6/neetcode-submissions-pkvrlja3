class Solution {
public:
    int interl(string s1,int x,string s2,int y,string s3,int z,
               vector<vector<int>> &dp){

        if(z==-1){
            return (x==-1 && y==-1);
        }

        if(dp[0][z]!=-1) return dp[0][z];

        if(x>=0 && y>=0 && s1[x]==s3[z] && s2[y]==s3[z]){
            dp[0][z] =
                interl(s1,x-1,s2,y,s3,z-1,dp) ||
                interl(s1,x,s2,y-1,s3,z-1,dp);
        }
        else if(x>=0 && s1[x]==s3[z]){
            dp[0][z] =
                interl(s1,x-1,s2,y,s3,z-1,dp);
        }
        else if(y>=0 && s2[y]==s3[z]){
            dp[0][z] =
                interl(s1,x,s2,y-1,s3,z-1,dp);
        }
        else{
            dp[0][z] = 0;
        }

        return dp[0][z];
    }

    bool isInterleave(string s1, string s2, string s3) {

        int x=s1.size(), y=s2.size(), z=s3.size();

        if(x+y!=z) return false;

        vector<vector<int>> dp(1,vector<int>(z,-1));

        return interl(s1,x-1,s2,y-1,s3,z-1,dp);
    }
};