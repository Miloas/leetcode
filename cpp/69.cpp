class Solution {
public:
    int sqrt(int x) {
        if(x==0)return 0;
        double pre,cur=1;
        for(int i=0;i<100;++i){
        	pre=cur;
        	cur=x/(2*pre)+pre/2.0;
        }
        return int(cur);
    }
};