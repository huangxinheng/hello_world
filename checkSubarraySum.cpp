class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map{{0,-1}};
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int t=(k==0)?sum:(sum%k);
            if(map.count(t)){
                if(i-map[t]>1)  // at least 2
                    return true;
            }else{
                map[t]=i;
            }
        }
        return false;
    }
};