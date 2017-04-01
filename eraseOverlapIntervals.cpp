/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval& a, Interval& b){
        return a.end < b.end;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
       if(intervals.size()<=1)
         return 0;
       int res=0;
       sort(intervals.begin(),intervals.end(),cmp);
       int last=intervals[0].end;
       for(int i=1;i<intervals.size();i++){
           if(intervals[i].start<last)
              res++;
           else 
             last=intervals[i].end;
       }
       return res;
    }
};