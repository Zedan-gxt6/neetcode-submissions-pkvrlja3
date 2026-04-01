class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        int i=0,j=0,maxsub=0;

        while(j<s.size()){
            m[s[j]]++;

            int maxi=0;
            for(auto &[key,val]:m){
                maxi=max(maxi,val);
            }

            if((j-i+1-maxi)<=k){
                maxsub=max(maxsub,j-i+1);
            }
            else{
                m[s[i]]--;
                i++;
            }

            j++;
        }

        return maxsub;
    }
};