class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> map(nums1.begin(),nums1.end());
        vector<int> res;
        for(int i=0;i<nums2.size();i++){
            if(map.count(nums2[i])>0){
                res.push_back(nums2[i]);
                map.erase(nums2[i]);
            }
        }
        return res;
    }
};