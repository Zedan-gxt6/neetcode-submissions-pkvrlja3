class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto p : m) {
            pq.push({p.second, p.first});
        }
        string ans;
        while (pq.size() >= 2) {
            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            ans.push_back(first.second);
            ans.push_back(second.second);

            first.first--;
            second.first--;

            if (first.first > 0) {
                pq.push(first);
            }
            if (second.first > 0) {
                pq.push(second);
            }
        }
        if (!pq.empty()) {
            auto last = pq.top();
            pq.pop();

            if (last.first > 1) {
                return "";
            }
            if (!ans.empty() && ans.back() == last.second) {
                return "";
            }
            ans.push_back(last.second);
        }
        return ans;
    }
};