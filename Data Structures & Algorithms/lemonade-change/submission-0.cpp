class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(2,0);
        for(int i:bills){
            if(i==5) change[0]++;
            else if(i==10){
                change[1]++;
                if(change[0]) change[0]--;
                else return false;
            }
            else if(i==20){
                if(change[1]) {
                    change[1]--;
                    if(change[0]) change[0]--;
                    else return false;
                }
                else if(change[0]>=3) change[0]-=3;
                else return false;
            }
        }
        return true;
    }
};