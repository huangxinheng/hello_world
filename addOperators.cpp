class Solution {
public:
    void dfs(string num,int target,long long diff,long long curRes,string tmp,vector<string>& res){
        if(num.size()==0 && curRes==target){
            res.push_back(tmp);
            return;
        }
        for(int i=1;i<=num.size();i++){
            string cur=num.substr(0,i);
            string next=num.substr(i);
            if(cur[0]=='0' && cur.size()>1) // number starts with 0
                return;
            if(tmp.size()>0){
                dfs(next,target,stoll(cur),curRes+stoll(cur),tmp+"+"+cur,res);
                dfs(next,target,-stoll(cur),curRes-stoll(cur),tmp+"-"+cur,res);
                dfs(next,target,diff*stoll(cur),(curRes-diff)+diff*stoll(cur),tmp+"*"+cur,res);
            }else{
                dfs(next,target,stoll(cur),stoll(cur),cur,res); //first one
            }
        }
        
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num,target,0,0,"",res);
        return res;
    }
};