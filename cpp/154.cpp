class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1;
        while(l < r){
        	int m = (l + r) >> 1;
        	if(num[m] > num[r]) l = m + 1;
        	else if (num[m] < num[r]) r = m;
        	else r--;
        }
        return num[l];
    }
};