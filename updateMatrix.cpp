class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return matrix;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                    q.push(make_pair(i,j));
                else
                    matrix[i][j]=INT_MAX;
            }
        
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            for(auto d:dir){
                int x=d[0]+t.first;
                int y=d[1]+t.second;
                if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y]<=matrix[t.first][t.second])
                    continue;
                matrix[x][y]=matrix[t.first][t.second]+1;
                q.push(make_pair(x,y));
            }
        }
        return matrix;
    }
};