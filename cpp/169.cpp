class Solution {
public:
    int majorityElement(vector<int> &num) {
        int key_value,ct=0;
        for(auto x:num) {
        	if(!ct||x==key_value) {
        		key_value = x;
        		ct++;
        	}
        	else {
        		--ct;	
        	}
        }
        return key_value;
    }
};