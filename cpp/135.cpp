class Solution {
public:
    int candy(vector<int> &ratings) {
 		int n =ratings.size();
 		vector<int> f(n,1),g(n,1);
 		for(int i=1;i<n;++i){
 			if(ratings[i]>ratings[i-1])f[i]=f[i-1]+1;
 		}
 		for(int i=n-2;i>=0;--i){
 			if(ratings[i]>ratings[i+1])g[i]=g[i+1]+1;
 		}
 		int res=0;
 		for(int i=0;i<n;++i){
 			res+=max(f[i],g[i]);
 		}
 		return res;
    }
};