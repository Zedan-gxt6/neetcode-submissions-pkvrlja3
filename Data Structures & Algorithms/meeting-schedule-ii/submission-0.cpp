/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            if(a.start!=b.start) return a.start<b.start;
            return a.end<b.end;
        });

        priority_queue<int,vector<int>,greater<int>> rooms;

        for(auto &interval:intervals){
            int st = interval.start,end=interval.end;
            if(rooms.empty()){
                rooms.push(end);
                continue;
            }
            int topEnd = rooms.top(); 
            if(st>=topEnd){
                rooms.pop();
                rooms.push(end);
            }
            else{
                rooms.push(end);
            }
        }

        return rooms.size();
    }
};
