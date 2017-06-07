class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int lower=0;
        int upper=0;
        int max_v=INT_MAX;
        int min_v=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min_v)
                upper=i;
            min_v=max(nums[i],min_v);
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>max_v)
                lower=i;
            max_v=min(nums[i],max_v);
        }
        return (lower==upper) ? 0:(upper-lower+1);   
    }
};