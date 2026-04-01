class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int a=0,b=s.size()-1;
        while(a<=b){
            if(s[a]!=s[b]){
                return isPalindrome(s, a + 1, b) || isPalindrome(s, a, b - 1);
            }
            a++; b--;
        }
        return true;
    }
};