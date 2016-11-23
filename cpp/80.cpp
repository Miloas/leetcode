class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n)return 0;
        int ct=1,key=A[0];
        for(int i=1;i<n;++i)
        	if(A[i]==key)ct++;
        	else break;
        if(ct==1){
        	return removeDuplicates(A+1,n-1)+1;
        }
        copy(A+ct,A+n,A+2);
        return removeDuplicates(A+2,n-ct)+2;
    }
};