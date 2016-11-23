class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> snum;
        for(auto p:num){
            snum.push_back(to_string(p));
        }
        sort(snum.begin(),snum.end(),
            [](string a,string b){
                return a+b>b+a;    
            });
        string res="";
        for(auto p:snum)res+=p;
        if(res[0]=='0')return "0";
        return res;
    }
};
