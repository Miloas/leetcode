class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
    	int n=(1<<S.size());
    	vector<vector<int>> res;
    	sort(S.begin(),S.end());
    	for(int i=0;i<n;++i){
    		vector<int> tmp;
    		for(int j=0;j<S.size();++j)if(i&(1<<j)){
    			if(j&&S[j-1]==S[j]&&!(i&(1<<(j-1)))) goto outloop;
    			tmp.push_back(S[j]);
    		}
    		res.push_back(tmp);
    		outloop:;
    	}    
    	return res;
    }
};