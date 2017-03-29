class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int res=1;
        if(points.empty())
            return 0;
        sort(points.begin(),points.end());
        int end=points[0].second;
        int start=points[0].first;
        for(int i=1;i<points.size();i++){
            if(points[i].first<=end){
                end=min(points[i].second,end);
            }
            else{
                end=points[i].second;
                res++;
            }
        }
        return res;
    }
};