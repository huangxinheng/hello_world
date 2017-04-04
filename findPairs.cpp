class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.empty())
            return 0;
        unordered_map<int,int> map;
        for(auto n:nums)
            map[n]++;
        int res=0;
        for(auto m:map){
            if(k==0 && m.second>1)
                ++res;
            if(k>0 && map.find(m.first+k)!=map.end())
                ++res;
        }
        return res;
    }
};