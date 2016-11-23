class Solution {
public:
    int largestRectangleArea(vector<int> &h) {
        int n = h.size(), res = 0;
        if(!n)return 0;
        vector<int> l(n),r(n);
        stack<int> st;
        for(int i=0;i<n;++i){
        	while(!st.empty()&&h[st.top()]>=h[i])st.pop();
        	l[i]=st.empty()?0:st.top()+1;
        	st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;--i){
        	while(!st.empty()&&h[st.top()]>=h[i])st.pop();
        	r[i]=st.empty()?n:st.top();
        	st.push(i);
        }
        for(int i=0;i<n;++i)
        	res=max(res,h[i]*(r[i]-l[i]));
        return res;
    }
};