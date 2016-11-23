class Solution {
public:
    int maxProduct(int a[], int n) {
        int res = a[0];
        int maxs = a[0], mins = a[0];
        for(int i=1;i<n;++i){
        	int t1 = maxs*a[i],
        		t2 = mins*a[i];
        	maxs = max(a[i],max(t1,t2));
        	mins = min(a[i],min(t1,t2));
        	res = max(res,maxs);
        }
        return res;
    }
};