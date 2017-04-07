class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        if(d.empty())
            return "";
        string res="";
        for(auto word:d){
            int index=0;
            for(int i=0;i<s.size();i++){
                if(index<word.size() && word[index]==s[i])
                    index++;
            }
            if(index==word.size() && word.size()>=res.size())
               if(word.size()>res.size() || res>word) //smallest lexicographical order
                 res=word;
        }
        return res;
    }
};