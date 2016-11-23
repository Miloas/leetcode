class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	copy(B,B+n,A+m);
        inplace_merge(A,A+m,A+m+n);
    }
};