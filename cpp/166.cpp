class Solution {
public:
    string fractionToDecimal(long long a, long long b) {
        if(a==0)return "0";
        string res="";
        res+=(a^b)<0?"-":"";
        a=llabs(a),b=llabs(b);
        res+=to_string(a/b);
        if(a%b==0)return res;
        res+='.';
        unordered_map<int,int> map;
        for(long long r=a%b;r;r%=b){
        	if(map.count(r)>0){
        	    int x=map[r];
        		res=res.substr(0,x)+'('+res.substr(x)+')';
        		break;
        	}
        	map[r]=res.size();
        	r*=10;
        	res+=to_string(r/b);
        }
        return res;
    }
};