class Solution {
public:
    string searchPal(string s,int left,int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;right++;
        }
        return s.substr(left+1,right-1-left);
    }
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        string res="";
        for(int i=0;i<s.size();i++){
            string t=searchPal(s,i,i);
            if(t.size()>res.size())
                res=t;
            t=searchPal(s,i,i+1);
            if(t.size()>res.size())
                res=t;
        }
        return res;
    }
};