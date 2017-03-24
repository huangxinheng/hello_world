class Solution {
public:
    bool search(vector<vector<char>>& board,vector<vector<bool>>& map,string word,int i,int j,int idx){
        if(idx==word.size())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[idx] || map[i][j])
            return false;
        map[i][j]=true;
        int res=search(board,map,word,i+1,j,idx+1)||search(board,map,word,i-1,j,idx+1)||search(board,map,word,i,j+1,idx+1)||search(board,map,word,i,j-1,idx+1);
        map[i][j]=false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty())
            return false;
        if(word=="")
            return true;
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> map(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(search(board,map,word,i,j,0))
                    return true;
            }
        return false;
    }
};