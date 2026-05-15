class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> d;
        for(int i=0;i<order.size();i++){
            d[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            int equal=0;
            string word=words[i]; string next=words[i+1];
            int ws=word.size(),ns=next.size();
            cout<<word<<" "<<next<<endl;
            for(int j=0;j<min(ws,ns);j++){
                if(d[word[j]]<d[next[j]]) break;
                if(d[word[j]]>d[next[j]]) return false;
                else if(d[word[j]]==d[next[j]]) equal++;
            }
            if(equal==min(ws,ns) && ns<ws) return false;
        }
        return true;
    }
};