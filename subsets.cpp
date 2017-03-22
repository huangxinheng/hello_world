class Solution {
public:
    void dfs(vector<int>& nums,vector<vector<int>>& res,vector<int>& sub,int start){
		res.push_back(sub);
		for(int i=start;i<nums.size();i++){
			sub.push_back(nums[i]);
			dfs(nums,res,sub,i+1);
			sub.pop_back();
		}
	}
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> sub;
		if(nums.empty())
			return res;
		dfs(nums,res,sub,0);
		return res;
    }
};
