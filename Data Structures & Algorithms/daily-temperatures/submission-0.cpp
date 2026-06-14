class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<int> st;
        st.push(0);
        vector<int> result(n,0);
        for(int i=1;i<n;i++){
            while(!st.empty() && t[i]>t[st.top()]){
                result[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
