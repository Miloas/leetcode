class Solution {
public:
    int compareVersion(string v1, string v2) {
    	int tok1,tok2;
        int p1 = v1.find("."),
        	p2 = v2.find(".");
        if(p1<0) tok1 = v1.empty()?0:stoi(v1);
        else     tok1 = stoi(v1.substr(0,p1));
        if(p2<0) tok2 = v2.empty()?0:stoi(v2);
        else     tok2 = stoi(v2.substr(0,p2));
        int dif = tok1 - tok2;
        if(dif==0){
        	if(p1 < 0 && p2 < 0) 
        		return 0;
        	v1 = p1 < 0 ? "0" : v1.erase(0,p1+1);
        	v2 = p2 < 0 ? "0" : v2.erase(0,p2+1);
        	return compareVersion(v1,v2);
        }
        return dif < 0 ? -1 : 1;
    }
};