class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1=s1.size();
        int n2=s2.size();

        if(n2<n1) return false;

        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(char c:s1){
            if(!m1.count(c)) {m1[c]=1; m2[c]=0;}
            else m1[c]++;
        }

        int i=0,j=n1-1;

        unordered_set<char> sett;

        for(int k=i;k<=j;k++){
            char c=s2[k];
            if(m1.count(c)){
                m2[c]++;
                if(m2[c]==m1[c]) sett.insert(c);
                else if(sett.find(c)!=sett.end()) sett.erase(c);

                if(sett.size()==m1.size()) return true;
            } 
        }
        while(j+1<n2){
            char prev=s2[i];
            char next=s2[j+1];
            i++; j++;
            if(m2.count(prev)){
                m2[prev]--; 
                if(m2[prev]==m1[prev]) sett.insert(prev);
                else if(sett.find(prev)!=sett.end()) sett.erase(prev);
            }
            if(m2.count(next)){
                m2[next]++;
                if(m2[next]==m1[next]) sett.insert(next);
                else if(sett.find(next)!=sett.end()) sett.erase(next);
            }
            if(sett.size()==m1.size()) return true;
        }
        return false;
    }
};
