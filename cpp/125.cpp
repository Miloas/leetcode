class Solution {
public:
    bool isPalindrome(string s) {
        string format_s="";
        for(auto ch:s)if(isalnum(ch)){
        	format_s+=toupper(ch);
        }
        string rformat_s = format_s;
        reverse(rformat_s.begin(),rformat_s.end());
        return format_s == rformat_s; 
    }
};