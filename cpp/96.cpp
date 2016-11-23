class Solution {
public:
    int numTrees(int n) {
        int res=1;
        for(int i=1;i<=n;i++)
        	res*=(4*i-2)/(i+1);
        return res;
    }
};