class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(char i:s){
            if(!m.count(i)) m[i]=1;
            else m[i]++;
        }
        vector<int> ans;
        unordered_set<char> seen;
        int curr_size=0;
        for(char i:s){
            seen.insert(i);
            curr_size++;
            m[i]--;
            if(m[i]==0) seen.erase(i);
            if(seen.size()==0){
                ans.push_back(curr_size);
                curr_size=0;
            }
        }
        return ans;
    }
};
