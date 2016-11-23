class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        for(auto p:s){
            res=res*26+p-'A'+1;
        }
        return res;
    }
};