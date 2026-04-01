class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> st; int n=0;
        st.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
          st.push_back(nums[i]); n++;
           while(1){

                int a=st[n],ma=a<0?a*-1:a;
                int b=st[n-1],mb=b<0?b*-1:b;
                st.pop_back(); st.pop_back(); n-=2;

                if(a<0 && b>0){
                    if(ma>mb){
                        st.push_back(a);
                        n++;
                    }
                    else if(mb>ma){
                        st.push_back(b);
                        n++;
                    }
                    else break;
                }
                else{
                    st.push_back(b);
                    st.push_back(a);
                    n+=2;
                    break;
                }
           }
        }
        return st;
    }
};