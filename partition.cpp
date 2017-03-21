class Solution {
public:
    bool isPal(string s,int left,int right){
		while(left<right){
			if(s[left++]!=s[right--])
				return false;
		}
		return true;
	}
	void dfs(string s,vector<string>& sub,vector<vector<string>>& res,int idx){
		if(idx==s.size()){
			res.push_back(sub);
			return;
		}
		for(int i=idx;i<s.size();i++){
			if(isPal(s,idx,i)){
				sub.push_back(s.substr(idx,i-idx+1));
				dfs(s,sub,res,i+1);
				sub.pop_back();
			}
		}
	}
    vector<vector<string>> partition(string s){
		vector<vector<string>> res;
		vector<string> sub;
		if(s.empty()){
			return res;
		}
		dfs(s,sub,res,0);
		return res;
	}
};	  