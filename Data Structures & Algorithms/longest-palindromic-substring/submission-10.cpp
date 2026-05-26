class Solution {
public:
    vector<int> expand(string s,int n,int i,int j){
        if(i-1>=0 && j+1<n && s[i-1]==s[j+1]){
            return expand(s,n,i-1,j+1);
        }
        return {i,j-i+1};
    }
    string longestPalindrome(string s) {
        int n=s.size(),maxl=1,maxi=0;
        vector<int> l(2,0),m(2,0);
        for(int i=0;i<n;i++){
            l=expand(s,n,i,i);
            if(i+1<n && s[i]==s[i+1]) m=expand(s,n,i,i+1);
            if(l[1]>maxl){
                maxl=l[1];
                maxi=l[0];
            }
            if(m[1]>maxl){
                maxl=m[1];
                maxi=m[0];
            }
        }
        return s.substr(maxi,maxl);
    }
};
