class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
       f(0,n,0,k);
       return res; 
    }
    void f(int s,int e,int d,int maxd){
    	if(d>=maxd){
    		res.push_back(tmp);
    		return;
    	}
    	for(int i=s+1;i<=e;++i){
    		tmp.push_back(i);
    		f(i,e,d+1,maxd);
    		tmp.pop_back();
    	}
    }
private:
	vector<vector<int>> res;
	vector<int> tmp;
};