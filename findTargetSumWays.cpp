class Solution {
public:
    void dfs(vector<int>&nums,int curSum,int target,int index,vector<int>& s,int& res){
        if(index==nums.size()){
            if(curSum==target){
                res++;
                return;
            }
        }else if(abs(target-curSum)<=s[index]){
        dfs(nums,curSum+nums[index],target,index+1,s,res);
        dfs(nums,curSum-nums[index],target,index+1,s,res);
        }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int res=0;
        if(nums.empty())
            return res;
        vector<int> s=nums;
        for(int i=nums.size()-2;i>=0;i--)
            s[i]+=s[i+1];
        dfs(nums,0,S,0,s,res);
        return res;
    }
};