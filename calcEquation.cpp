class Solution {
public:
    double check(unordered_map<string,unordered_map<string,double>>& map,unordered_set<string>&s,string up,string down){
        if(map[up].find(down)!=map[up].end())
            return map[up][down];
        if(map[down].find(up)!=map[up].end())
            return map[down][up];
        for(auto m:map[up]){
            if(s.find(m.first)==s.end()){
                s.insert(m.first);
                double ans=check(map,s,m.first,down);
                if(ans)
                    return (m.second)*ans;
            }
        }
        return 0;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string,unordered_map<string,double>> map;
        for(int i=0;i<equations.size();i++){
            map[equations[i].first][equations[i].second]=values[i];
            if(values[i]!=0)
                map[equations[i].second][equations[i].first]=1.0/values[i];
        }
        vector<double> res;
        for(auto q:queries){
            unordered_set<string> s;
            double ans=check(map,s,q.first,q.second);
            if(ans)
                res.push_back(ans);
            else
                res.push_back(-1);
        }
        return res;
    }
};