class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int a=0,b=0;
        string ans;
        while(a<w1.size() && b<w2.size()){
            ans+=w1[a++];
            ans+=w2[b++];
        }
        while(a<w1.size()) ans+=w1[a++];
        while(b<w2.size()) ans+=w2[b++];
        return ans;
    }
};