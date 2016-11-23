class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    	int n = s.size();
        vector<bool> f(n+1);
        f[n]=true;
        for(int i=n-1;i>=0;--i){
        	for(auto w:dict){
        		if(i+w.size()<=n&&f[i+w.size()]&&w==s.substr(i,w.size())){
        			f[i]=true;
        			break;
        		}
        	}
        }
        return f[0];
    }
};