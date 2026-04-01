class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size(); int ans=0;
        vector<int> l(n,0);
        int maxl=0;
        for(int i=0;i<n;i++){
            if(h[i]>=maxl) maxl=h[i]; 
            l[i]=maxl;
        }
        vector<int> r(n,0);
        int maxr=0;
        for(int i=n-1;i>=0;i--){
            if(h[i]>=maxr) maxr=h[i]; 
            r[i]=maxr;
        }
        for(int i=0;i<n;i++){
            int a=min(l[i],r[i]);
            if(a > h[i]) ans+=(a-h[i]);
        }
        return ans;
    }
};
