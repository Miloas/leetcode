class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
    	if(matrix.empty())return 0;
    	int m = matrix.size(), n = matrix[0].size(),res=0;
    	vector<vector<int>> h(m,vector<int>(n));
    	for(int i=0;i<m;++i)
    		for(int j=0;j<n;++j)
    			if(matrix[i][j]=='0')
    				h[i][j]=0;
    			else if(!i)
    				h[i][j]=1;
    			else
    				h[i][j]=h[i-1][j]+1;

    	for(int k=0;k<m;++k){
	    	stack<int> st;
	    	vector<int> l(n),r(n);
	    	for(int i=0;i<n;++i){
	    		while(!st.empty()&&h[k][st.top()]>=h[k][i])st.pop();
	    		l[i]=st.empty()?0:st.top()+1;
	    		st.push(i);
	    	}
	    	while(!st.empty())st.pop();
	    	for(int i=n-1;i>=0;--i){
	    		while(!st.empty()&&h[k][st.top()]>=h[k][i])st.pop();
	    		r[i]=st.empty()?n:st.top();
	    		st.push(i);
	    	}
	    	for(int i=0;i<n;++i){
	    		res=max(res,h[k][i]*(r[i]-l[i]));
	    	}
    	}			
    	return res;
    }
};