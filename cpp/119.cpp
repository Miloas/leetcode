class Solution {
public:
    vector<int> getRow(int n) {
    	n++;
        vector<int> f(n);
        f[0]=1;f[1]=0;
        for(int i=1;i<n;++i)
        	for(int j=n;j>=0;--j)
        		f[j]=f[j-1]+f[j];
        return f;
    }
};