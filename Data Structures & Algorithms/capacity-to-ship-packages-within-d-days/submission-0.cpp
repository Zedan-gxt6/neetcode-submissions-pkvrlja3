class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=0,sum=0;
        for(auto i:weights){
            maxi=max(maxi,i);
            sum+=i;
        }
        int l=maxi,r=sum,mid,mydays=0,filler=0;
        while(l<r){
            mid=l+(r-l)/2;
            
            mydays=1;
            filler=0;
            for(int i:weights){
                filler+=i;
                if(filler>mid){
                    filler=i;
                    mydays++;
                }
            }
            cout<<mid<<" "<<mydays<<endl;

            if(mydays<=days) r=mid;
            else l=mid+1;
        }
        return l;
    }
};