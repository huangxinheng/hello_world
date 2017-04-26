class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp;
        dp.push_back(0);
        for(int i=1;i<=num;i++){
            if(i%2==0){
                dp.push_back(dp[i/2]);
            }else{
                dp.push_back(dp[i/2]+1);
            }
        }
        return dp;
    }
};