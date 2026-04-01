class Solution {
public:
    bool isPalindrome(string ss) {
        string s;
        for(char c:ss){
            if(c>='0' && c<='9') s+=c;
            else if(c>='a' && c<='z') s+=c;
            else if(c>='A' && c<='Z') s+=(c+32);
        }
        cout<<s;
        int a=0,b=s.size()-1;
        while(a<b){
            if(s[a++]!=s[b--]) return false;
        }
        return true;
    }
};
