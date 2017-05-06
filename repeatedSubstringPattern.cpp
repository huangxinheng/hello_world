class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string test=s+s;
        string t = test.substr(1,test.length()-2);
        if(t.find(s)!=string::npos)
            return true;
        return false;
    }
};