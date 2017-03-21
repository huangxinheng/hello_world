class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')
                count++;
            else if(i+1<s.size() && s[i+1]!=' ')
                count=0;
        }
        return count;
    }
};