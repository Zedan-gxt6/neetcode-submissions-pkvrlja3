class Solution {
public:
    long long int mySqrt(long long int x) {
        if(x==0) return 0;
        long long int l=1,r=x,mid;
        while(l<r){
            mid=l+(r-l+1)/2;
            if(mid*mid>x) r=mid-1;
            else l=mid;
        }
        return l;
    }
};