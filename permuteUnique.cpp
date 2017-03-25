class Solution {
public:
    void dfs(vector<int>& nums,vector<bool>& visited,vector<int>& sub,vector<vector<int>>& res,int len){
        if(len==nums.size()){
            res.push_back(sub);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==false){
                if(i>0 && nums[i]==nums[i-1] && visited[i-1]==false)
                    continue;
                sub.push_back(nums[i]);
                visited[i]=true;
                dfs(nums,visited,sub,res,len+1);
                sub.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        vector<bool> visited(nums.size(),false);
        sort(nums.begin(),nums.end());
        dfs(nums,visited,sub,res,0);
        return res;
    }
};