class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l=1,r=x,mid;
        while(l<r){
            mid=l+(r-l+1)/2;
            if((long long )mid*mid>x) r=mid-1;
            else l=mid;
        }
        return l;
    }
};