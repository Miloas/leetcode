class Solution {
public:
	void g(string &s,int i){
		if(i==s.size()){
			res.push_back(tmp);
			return;
		}
		for(int j=0;j<s.size();++j){
			if(f[i][j]){
				tmp.push_back(s.substr(i,j-i+1));
				g(s,j+1);
				tmp.pop_back();
			}
		}
	}
    vector<vector<string>> partition(string s) {
    	int n = s.size();
    	f.assign(n,vector<bool>(n));
    	for(int i=0;i<n;++i){
    		f[i][i]=true;
    		if(i+1<n&&s[i]==s[i+1])f[i][i+1]=true;
    	}
    	for(int i=n-1;i>=0;--i){ //注意递推方向
    		for(int len=3;i+len-1<n;++len){
    			int j=i+len-1;
    			f[i][j]=f[i+1][j-1]&&s[i]==s[j];
    		}
    	}
    	res.clear();
    	g(s,0);
    	return res;
    }
private:
	vector<vector<bool>> f;
	vector<vector<string>> res;
	vector<string> tmp;
};