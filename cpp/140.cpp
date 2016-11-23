class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
    	int n = s.size();
        unordered_map<int,vector<string>> ump;
        vector<string> vs;
        vs.push_back("");
        ump[n]=vs;
        for(int i=n-1;i>=0;--i){
        	vector<string> tmp;
        	for(int j=i+1;j<=n;++j){
        		if(dict.count(s.substr(i,j-i))){
        			for(auto w:ump[j]){
        				tmp.push_back(s.substr(i,j-i)+(w==""?"":(" "+w)));
        			}
        		}
        	}
        	ump[i]=tmp;
        }
        return ump[0];
    }
};