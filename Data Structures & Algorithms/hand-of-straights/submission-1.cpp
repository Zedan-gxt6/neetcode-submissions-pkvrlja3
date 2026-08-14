class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;

        sort(hand.begin(),hand.end());
        unordered_map<int,int> freqMap;
        for(int i:hand) freqMap[i]++;

        vector<int> nums;
        for(auto [i,count]:freqMap) nums.push_back(i);

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            while(freqMap[nums[i]]>0){
                freqMap[nums[i]]--;
                for(int j=i+1;j<i+groupSize;j++){
                    if(j>=nums.size()) return false;
                    if(freqMap[nums[j]]>0){
                        if(nums[j]==nums[j-1]+1){
                            freqMap[nums[j]]--;
                        }
                        else return false;
                    } 
                    else return false;
                }
            }
            
        }
        return true;
    }
};
