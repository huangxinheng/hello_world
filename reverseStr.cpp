class Solution {
public:
    void reverse(string& s,int start,int end){
        while(start<=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2 * k) {
            int end=(i+k)<s.size()?(i+k):s.size();
            reverse(s,i,end-1);
        }
      return s;
    }
};