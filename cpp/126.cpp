class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        ump.clear();res.clear();
        queue<string> q;
        vector<string> v;
        unordered_map<string,int> d;
        v.push_back(start);
        for(auto x:dict)
            d[x]=INT_MAX;
        d[start]=0;
        dict.insert(end);
        q.push(start);
        int min=INT_MAX;
        while(!q.empty()){
            auto cur = q.front();q.pop();
            string tmp_cur=cur;
            int step = d[cur]+1;
            if(step>min)break;
            for(int i=0;i<cur.size();++i){
                char tmp = cur[i];
                for(int j='a';j<='z';++j){
                    cur[i]=j;
                    if(d.count(cur)){
                        if(step>d[cur])continue;
                        else if(step<d[cur]){
                          q.push(cur);
                          d[cur]=step;
                        }

                        if(ump.count(cur))ump[cur].push_back(tmp_cur);
                        else{
                          v.clear();
                          v.push_back(tmp_cur);
                          ump[cur]=v;
                         }
                         if(cur == end) min = step;
                    }
                }
                cur[i]=tmp;
            }
        }
        v.clear();
        dfs(end,start,v);
        return res;
    }
    void dfs(string w,string s,vector<string> v){
        if(w==s){
            v.insert(v.begin(),s);
            res.push_back(v);
            v.erase(v.begin());
            return ;
        }
        v.insert(v.begin(),w);
        if(ump.count(w)){
            for(auto x:ump[w]){
                dfs(x,s,v);
            }
        }
        v.erase(v.begin());
    }
private:
    unordered_map<string,vector<string>> ump;
    vector<vector<string>> res;
};

