class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for (char c : tasks) {
            freq[c]++;
        }

        priority_queue<int> pq;

        for (auto &p : freq) {
            pq.push(p.second);
        }

        queue<pair<int, int>> cool; 
        // {availableTime, remainingCount}

        int time = 0;

        while (!pq.empty() || !cool.empty()) {
            time++;

            // bring back tasks whose cooldown is over
            if (!cool.empty() && cool.front().first == time) {
                pq.push(cool.front().second);
                cool.pop();
            }

            if (!pq.empty()) {
                int cnt = pq.top();
                pq.pop();

                cnt--;

                if (cnt > 0) {
                    cool.push({time + n + 1, cnt});
                }
            }
        }

        return time;
    }
};