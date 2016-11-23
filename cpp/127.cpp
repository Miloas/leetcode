class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string,int> d;
        queue<string> q;
        d[start]=0;
        dict.insert(end);
        q.push(start);
        while(!q.empty()){
        	auto cur = q.front();q.pop();
        	if(cur==end)return d[end]+1;
        	int curd = d[cur];
        	for(int i=0;i<cur.size();++i){
        		char tmp = cur[i];
        		for(int j='a';j<='z';++j){
        			cur[i]=j;
        			if(dict.count(cur)){
        				dict.erase(cur);
        				q.push(cur);
        				d[cur]=curd+1;
        			}
        		}
        		cur[i]=tmp;
        	}
        }
        return 0;
    }
};