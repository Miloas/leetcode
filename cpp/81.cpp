class Solution {
public:
    bool search(int A[], int n, int target) {
       return f(A,0,n-1,target)!=-1; 
    }
    int f(int A[],int l,int r,int target){
        if(l>r)return -1;
        int m=l+(r-l)/2;
        if(A[m]==target) return m;
        if(A[m]>A[l]){
            if(target>=A[l]&&target<A[m])
                return f(A,l,m-1,target);
            else
                return f(A,m+1,r,target);
        }
        else if(A[m]==A[l]) 
            return f(A,l+1,r,target);
        if(A[r]>A[m]){
            if(target>A[m]&&target<=A[r])
                return f(A,m+1,r,target);
            else
                return f(A,l,m-1,target);
        }
        else if(A[r]==A[m])
            return f(A,l,r-1,target);
        return -1;
    }
};