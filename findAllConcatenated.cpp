class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words){
        vector<string> res;
        if(words.size()<=2)
            return res;
        unordered_set<string> dict(words.begin(), words.end());
        for (string word : words) {
            int n = word.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            dict.erase(word);
            for (int i=0;i<n+1;++i) {
               for(int j=0; j<i;++j){
                   if(dp[j] && dict.count(word.substr(j,i-j))){
                       dp[i]=true;
                       break;
                   }
               }
            }
            if(dp.back() && word!="")
                res.push_back(word);
            dict.insert(word);
        }
        return res;
    }
};