class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty())
            return;
        vector<int> t=nums;
        sort(t.begin(),t.end());
        int j=(nums.size()+1)/2;
        int k=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i%2==0)
                nums[i]=t[--j];
            else
                nums[i]=t[--k];
        }
    }
};