class Solution {
public:
    int maximumGap(vector<int> &num) {
		int n = num.size();
		if(n <= 1)return 0;
		int mins = *min_element(num.begin(),num.end()),
			maxs = *max_element(num.begin(),num.end()),
			gap  = (int)ceil((double)(maxs-mins)/(n-1)),
			nb   = (maxs-mins)/gap + 1;
		vector<int> a(nb,INT_MAX) , b(nb,INT_MIN);
		for(auto x : num){
			int i = (x - mins)/gap;
			a[i] = min(a[i],x);
			b[i] = max(b[i],x);
		}
		int res = 0, last = mins;
		for(int i = 0; i < nb; ++i){
			if(a[i] < INT_MAX){
				res = max(res,a[i]-last);
				last = b[i];
			}
		}
		return max(res,maxs-last);
    }
};