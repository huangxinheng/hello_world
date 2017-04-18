class Solution {
public:
    bool isValid(string s){
        int cnt=0;
        for(auto c:s){
            if(c=='(')
                cnt++;
            if(c==')'){
                if(cnt==0)
                    return false;
                cnt--;
            }
        }
        return cnt==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        q.push(s);
        unordered_map<string,int> visited;
        ++visited[s];
        bool found=false;
        while(!q.empty()){
            s=q.front();q.pop();
            cout<<s<<endl;
            if(isValid(s)){
                res.push_back(s);
                found=true;
            }
            if(found)
                continue;
            for(int i=0;i<s.size();i++){
                if(s[i]!='('&&s[i]!=')')
                    continue;
                string t=s.substr(0,i)+s.substr(i+1);
                if(visited.find(t)==visited.end()){
                    ++visited[t];
                    q.push(t);
                }
            }
        }
        return res;
    }
};