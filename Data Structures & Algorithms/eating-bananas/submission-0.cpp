class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for (int i : piles) maxi = max(maxi, i);

        int a = 1, b = maxi;

        while (a < b) {
            int mid = a + (b - a) / 2;

            long long totalHours = 0;

            for (int i : piles) {
                totalHours += (i + mid - 1) / mid; 
            }

            if (totalHours > h)
                a = mid + 1;
            else
                b = mid;
        }

        return a;
    }
};