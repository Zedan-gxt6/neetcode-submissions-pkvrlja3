class Solution {
public:
    vector<string> neighbours(string s){
        vector<string> nbs;
        for(int i=0;i<4;i++){
            if(s[i]=='9'){
                s[i]='0';
                nbs.push_back(s);
                s[i]='9';
            }
            else{
                s[i]++;
                nbs.push_back(s);
                s[i]--;
            }
            if(s[i]=='0'){
                s[i]='9';
                nbs.push_back(s);
                s[i]='0';
            }
            else{
                s[i]--;
                nbs.push_back(s);
                s[i]++;
            }
        }
        return nbs;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        unordered_set<string> vis;

        unordered_set<string> deads(deadends.begin(),deadends.end());
        if(deads.count("0000")) return -1;
        q.push({"0000",0});
        vis.insert("0000");

        while(!q.empty()){
            auto top=q.front(); q.pop();
            if(top.first==target) return top.second;
                auto nbs=neighbours(top.first);
                for(auto nb:nbs){
                    if(!vis.count(nb) && !deads.count(nb)){
                        vis.insert(nb);
                        q.push({nb,top.second+1});
                    }
                }
        }
        return -1;
    }
};