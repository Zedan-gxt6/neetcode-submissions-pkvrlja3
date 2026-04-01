class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++){
            gas[i] -= cost[i];
        }
        int total = 0;
        for(int i = 0; i < n; i++)
            total += gas[i];

        if(total < 0) return -1;
        for(int i = 0; i < n; i++){
            int sum = 0;
            int j;

            for(j = i; j < i + n; j++){
                sum += gas[j % n];

                if(sum < 0){
                    i = j;   
                    break;
                }
            }

            if(j == i + n)  
                return i;
        }

        return -1;
    }
};
