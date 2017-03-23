class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=0.5*(low+high);
            int cnt=0;
            for(auto n:nums){
                if(n<=mid)
                    cnt++;
            }
            if(cnt<=mid)
                low=mid+1;
            else
                high=mid;
        }
        return high;
    }
};