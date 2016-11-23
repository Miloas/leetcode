class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
    	vector<vector<int>> res;
    	sort(S.begin(),S.end());
        for(int i=0;i<1<<S.size();++i){
        	vector<int> tmp;
        	for(int j=0;j<S.size();++j){
        		if(i&(1<<j))tmp.push_back(S[j]);
        	}
        	res.push_back(tmp);
        }
        return res;
    }
};