class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128,-1);
        int start=-1;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(map[s[i]]>start){
                start=map[s[i]]; // update position
            }
            map[s[i]]=i;
            res=max(res,i-start);
        }
        return res;
    }
};