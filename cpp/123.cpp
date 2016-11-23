class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        if(!n) return 0;
        int hold1=INT_MIN,hold2=INT_MIN,sale1=0,sale2=0;
        for(auto x:prices){
            hold1=max(hold1,-x);
            sale1=max(sale1,x+hold1);
            hold2=max(hold2,sale1-x);
            sale2=max(sale2,hold2+x);
        }
        return sale2;
    }
};