class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxc=0,maxf=0;
        unordered_map<char,int> m;
        for(auto i:tasks){
            m[i]++;
            if(m[i]>maxf){
                maxf=m[i];
                maxc=1;
            }
            else if(m[i]==maxf) maxc++;
        }
        return max((int)tasks.size(),(maxf-1)*(n+1)+maxc);
    }
};
