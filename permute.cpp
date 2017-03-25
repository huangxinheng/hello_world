class Solution {
public:
    void dfs(vector<int>& nums,vector<bool>& visited,vector<int>& sub,vector<vector<int>>& res,int idx){
        if(idx==nums.size()){
            res.push_back(sub);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                sub.push_back(nums[i]);
                dfs(nums,visited,sub,res,idx+1);
                sub.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        vector<bool> visited(nums.size(),false);
        dfs(nums,visited,sub,res,0);
        return res;
        
    }
};