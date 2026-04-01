class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        unordered_map<char, int> need;   // freq required from t
        unordered_map<char, int> have;   // freq in current window

        for (char x : t) need[x]++;

        int i = 0, j = 0;
        int formed = 0, target = need.size();
        int mini = 0, minl = sn + 1;

        while (j < sn) {
            char curr = s[j];
            if (need.count(curr)) {
                have[curr]++;
                if (have[curr] == need[curr]) formed++;
            }

            // shrink from left as long as window is valid
            while (formed == target) {
                // record if this window is smaller
                if (j - i + 1 < minl) {
                    mini = i;
                    minl = j - i + 1;
                }

                char left = s[i];
                if (need.count(left)) {
                    have[left]--;
                    if (have[left] < need[left]) formed--;
                }
                i++;
            }

            j++;
        }

        return (minl == sn + 1) ? "" : s.substr(mini, minl);
    }
};