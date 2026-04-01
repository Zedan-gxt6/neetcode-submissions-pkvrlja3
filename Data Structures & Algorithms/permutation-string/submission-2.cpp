class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.size(), n2 = s2.size();
        if(n2 < n1) return false;

        unordered_map<char,int> m1, m2;

        for(char c: s1) m1[c]++;

        int matched = 0;

        for(int i=0;i<n1;i++){
            char c = s2[i];
            if(m1.count(c)){
                m2[c]++;
                if(m2[c] == m1[c]) matched++;
                else if(m2[c] == m1[c] + 1) matched--;
            }
        }

        if(matched == m1.size()) return true;

        for(int i=0,j=n1; j<n2; i++,j++){

            char prev = s2[i];
            char next = s2[j];

            if(m1.count(prev)){
                m2[prev]--;
                if(m2[prev] == m1[prev]) matched++;
                else if(m2[prev] == m1[prev] - 1) matched--;
            }

            if(m1.count(next)){
                m2[next]++;
                if(m2[next] == m1[next]) matched++;
                else if(m2[next] == m1[next] + 1) matched--;
            }

            if(matched == m1.size()) return true;
        }

        return false;
    }
};