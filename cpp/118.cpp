class Solution {
public:
    vector<vector<int> > generate(int n) {
        vector<vector<int> > f;
        for(int i=0;i<n;++i){
            vector<int> tmp(i+1);
            f.push_back(tmp);
        }
        for(int i=0;i<n;++i) f[i][0] = f[i][i] = 1;
    	for(int i=1;i<n;++i)
    		for(int j=1;j<i;++j)
    			f[i][j]=f[i-1][j-1]+f[i-1][j];
    	return f;
    }
};