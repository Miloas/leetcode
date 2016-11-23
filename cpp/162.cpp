class Solution {
public:
    int findPeakElement(const vector<int> &num) {
    	int l = 0, r = num.size()-1;
    	while(l < r) {
    		int m = (l + r) >> 1;
    		if(num[m] > num[m+1]) r = m;
    		else l = m+1;
    	}
    	return l;
    }
};