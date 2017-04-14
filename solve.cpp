class Solution {
public:
    void check(vector<vector<char>>& board,int x,int y){
        if(board[x][y]=='O'){
            board[x][y]='$';
            if(x>1)
                check(board,x-1,y);
            if(y>1)
                check(board,x,y-1);
            if(y+1<board[0].size())
                check(board,x,y+1);
            if(x+1<board.size())
                check(board,x+1,y);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty())
            return;
        for(int i=0;i<board.size();i++){
            check(board,i,0);
            check(board,i,board[0].size()-1);
        }
        for(int j=0;j<board[0].size();j++){
            check(board,0,j);
            check(board,board.size()-1,j);
        }
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='$')
                    board[i][j]='O';
            }
    }
};