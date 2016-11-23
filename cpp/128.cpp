class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> us;
        for(auto x:num)us.insert(x);
        int res = -1;
        for(auto x:num){
        	int s = x, e = x;
        	while(us.count(s-1))us.erase(s--);
        	while(us.count(e+1))us.erase(e++);
        	res = max(res, e-s+1);
        }	
        return res;
    }
};