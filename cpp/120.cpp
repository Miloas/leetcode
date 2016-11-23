class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	int n=triangle.size();
    	vector<int> f = triangle[n-1];
    	for(int i=n-2;i>=0;--i)
    		for(int j=0;j<triangle[i].size();++j)
    			f[j]=min(f[j],f[j+1])+triangle[i][j];
    	return f[0];
    }
};