class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
 		int res = 0, tot = 0, t = 0, n = gas.size();
 		for(int i = 0; i < n; ++i){
 			int d = gas[i]-cost[i];
 			tot += d;
 			t   += d;
 			if(t < 0){
 				t = 0;
 				res=i+1;
 			}
 		}       
 		return tot < 0 ? -1 : res;
    }
};