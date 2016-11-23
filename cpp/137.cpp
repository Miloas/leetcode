class Solution {
public:
    int singleNumber(int A[], int n) {
 		int ones=0,twos=0,comminbits;
 		for(int i=0;i<n;++i){
 			twos |= ones&A[i];
 			ones ^= A[i];
 			comminbits = ones&twos;
 			ones&=~comminbits;
 			twos&=~comminbits;
 		}       
 		return ones;
    }
};