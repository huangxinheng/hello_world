class Solution {
public:
    static bool cmp(int& a,int& b){
        return (to_string(a)+to_string(b))>(to_string(b)+to_string(a));
    }
    string largestNumber(vector<int>& nums) {
        string res="";
        sort(nums.begin(),nums.end(),cmp);
        for(auto n:nums)
            res+=to_string(n);
        if(res[0]=='0')
            return "0";
        return res;
    }
};