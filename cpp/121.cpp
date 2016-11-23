class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(!prices.size()) return 0;
        int mins=INT_MAX,res=INT_MIN;
        for(auto x:prices){
        	mins=min(mins,x);
        	res=max(res,x-mins);
        }
        return res;
    }
};