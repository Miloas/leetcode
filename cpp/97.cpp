class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(m+n!=s3.size())return false;
        vector<vector<bool>> f(m+2,vector<bool>(n+2));
        f[0][0]=true;
        for(int i=0;i<=m;++i)
        	for(int j=0;j<=n;++j)if(f[i][j]){
        		if(s1[i]==s3[i+j])
        			f[i+1][j]=true;
        		if(s2[j]==s3[i+j])
        			f[i][j+1]=true;
        	}
        return f[m][n];
    }
};