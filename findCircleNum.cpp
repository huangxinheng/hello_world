class Solution {
public:
    void dfs(vector<vector<int>>& M,vector<bool>& visited,int i){
        for(int j=0;j<M.size();j++){
            if(i==j)
                continue;
            if(M[i][j]==1 && !visited[j]){
                visited[j]=1;
                dfs(M,visited,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(),false);
        int res=0;
        for(int i=0;i<M.size();i++){
            if(!visited[i]){
                res++;
                dfs(M,visited,i);
            }
        }
        return res;
    }
};