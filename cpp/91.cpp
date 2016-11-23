class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())return 0;
        int n=s.size();
        vector<int> f(n+1);
        f[0]=1;
        for(int i=0;i<n;++i){
        	if(s[i]=='0')
        		f[i+1]=0;
        	else
        		f[i+1]=f[i];
        	if(i&&s[i-1]>'0'&&s[i-1]<'2'||s[i-1]=='2'&&s[i]<='6')
        		f[i+1]+=f[i-1];
        }
        return f[n];
    }
};