class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size(),
            n = dungeon[0].size();
        vector<vector<int>> f(m,vector<int>(n,0));
        for(int i=m-1;i>=0;--i){
        	for(int j=n-1;j>=0;--j){
        		if(i==m-1&&j==n-1)
        			f[i][j]=max(1-dungeon[i][j],1);
        		if(i+1<m)
        			f[i][j]=max(f[i+1][j]-dungeon[i][j],1);
        		if(j+1<n)
        			if(f[i][j])
        				f[i][j]=min(f[i][j],max(f[i][j+1]-dungeon[i][j],1));
        			else
        				f[i][j]=max(f[i][j+1]-dungeon[i][j],1);
        	}
        }
        return f[0][0];
    }
};