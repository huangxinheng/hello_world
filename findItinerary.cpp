class Solution {
public:
    bool dfs(unordered_map<string,map<string,int>>& map,vector<string>&res,string from,int len){
        if(res.size()==len)
            return true;
        for(auto m=map[from].begin();m!=map[from].end();m++){
            if(m->second>0){
                m->second--;
                res.push_back(m->first);
                if(dfs(map,res,m->first,len))
                    return true;
                res.pop_back();
                m->second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        if(tickets.empty())
            return res;
        unordered_map<string,map<string,int>> map;
        for(auto t:tickets)
            map[t.first][t.second]++;
        res.push_back("JFK");
        dfs(map,res,"JFK",tickets.size()+1);
        return res;
    }
};