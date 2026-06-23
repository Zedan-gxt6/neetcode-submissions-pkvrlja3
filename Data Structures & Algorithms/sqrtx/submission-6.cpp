class Solution {
public:
    int mySqrt(int x) {
        // if(x==0) return 0;
        int l=0,r=x,mid;
        while(l<r){
            mid=l+(r-l)/2 + 1;
            if((long long )mid*mid>x) r=mid-1;
            else l=mid;
        }
        return l;
    }
};