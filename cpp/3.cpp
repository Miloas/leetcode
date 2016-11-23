class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int f[128], ret=0,i=0,j=0;
        memset(f,-1,sizeof(f));
        while(j<s.size()){
            if(f[s[j]]<i)ret=max(j-i+1,ret);
            else i=f[s[j]]+1;
            f[s[j]]=j++;
        }
        return ret;
    }
};
