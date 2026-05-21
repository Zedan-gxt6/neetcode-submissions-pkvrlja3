class Solution {
public:
    bool helper(string a,string b){
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) count++;
        }
        return count==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size()+1,end=-1;
        vector<vector<int>> A(n);
        for(int i=0;i<n-1;i++){
            if(wordList[i]==endWord){
                end=i; 
                break;
            }
        }
        if(end==-1) return 0;
        wordList.push_back(beginWord);
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string s=wordList[i],p=wordList[j];
                if(helper(s,p)){
                    A[i].push_back(j);
                    A[j].push_back(i);
                }
            }
        }
        queue<pair<int,int>> q;
        q.push({n-1,1});
        while(!q.empty()){
            auto top=q.front(); q.pop();
            vis[top.first]=true;
            if(top.first==end) return top.second;
            for(auto ne:A[top.first]){
                if(!vis[ne]) q.push({ne,top.second+1});
            }
        }
        return 0;
    }
};
