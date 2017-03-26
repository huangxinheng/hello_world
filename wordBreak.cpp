class Solution {
public:
    bool inDict(string s,vector<string>& map){
        for(auto m:map)
            if(s==m)
                return true;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())
            return false;
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
       for(int i=0;i<s.length()+1;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&inDict(s.substr(j,i-j),wordDict))
                    dp[i]=true;
            }
        }
        return dp[s.length()];
    }
};