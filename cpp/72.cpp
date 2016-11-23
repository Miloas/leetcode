class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> f(2,vector<int>(word2.size()+1));
        iota(f[0].begin(),f[0].end(),0);
        for(int i=0;i<word1.size();++i){
        	f[i+1&1][0]=i+1;
        	for(int j=0;j<word2.size();++j)
        		f[i+1&1][j+1]=word2[j]==word1[i]?f[i&1][j]:min(f[i&1][j],min(f[i+1&1][j],f[i&1][j+1]))+1;	
        }
        return f[word1.size()&1][word2.size()];
    }
};