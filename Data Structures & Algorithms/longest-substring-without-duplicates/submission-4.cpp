class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int i=0,j=0,max=1;
        unordered_map<char,int> h;
        while(j<s.size()){
            if(h.count(s[j])==0) h[s[j]]=j;
            else {
                if(h[s[j]]<i) {
                    h[s[j]]=j; 
                    j++; 
                    continue;
                }
                if(j-i>max) max=j-i;
                i=h[s[j]]+1;
                h[s[j]]=j;
            }
            j++;
        }
        if(j-i>max) max=j-i;
        return max;
    }
};
