class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto n:nums)
            sum+=n;
        if(sum%2)
            return false;
        sum=sum/2;
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        for(auto n:nums)
            for(int j=sum;j>=n;j--)
                dp[j]=dp[j]|dp[j-n];
        return dp[sum];
    }
};