class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=0;
        for(int i:piles) maxi=max(maxi,i);
        int l=1,r=maxi,mid,mh=0;
        while(l<r){
            mid=l+(r-l)/2;
            mh=0;
            for(int i:piles){
                mh+=((i/mid)+((i%mid)>0?1:0));
            }
            if(mh>h) l=mid+1;
            else r=mid;
        }
        return l;
    }
};
