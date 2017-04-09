class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        vector<int> map(128,0);
        for(int i=0;i<s.size();i++){
            map[s[i]-'a']++;
            map[t[i]-'a']--;
        }
        for(int i=0;i<map.size();i++)
            if(map[i]!=0)
                return false;
        return true;
    }
};