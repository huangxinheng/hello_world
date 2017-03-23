class Solution {
public:
    vector<int> grayCode(int n) {
        int max=1<<n;
        vector<int> res;
        for(int i=0;i<max;i++){
            int gray=(i>>1)^i;
            res.push_back(gray);
        }
        return res;
    }
};