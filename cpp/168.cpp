class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        while(n){
        	res=(char)('A'-1+(n%26?n%26:26))+res;
        	n=(n-1)/26;
        }
        return res;
    }
};