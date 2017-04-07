class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_map<int,int> map{{0,-1}};
        int sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]==0)?-1:1;
            if(map.count(sum)){
                res=max(res,i-map[sum]);
            }else
                map[sum]=i;
        }
        return res;
    }
};