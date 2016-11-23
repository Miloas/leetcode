/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &p) {
        int res = 0, n = p.size();
        for(int i = 0; i < n; ++i){
        	int samepoint = 1;
        	unordered_map<double,int> mp;
        	for(int j = i+1; j < n; ++j){
        		if(p[i].x == p[j].x && p[i].y == p[j].y) samepoint ++;
        		else if(p[i].x == p[j].x) mp[INT_MAX]++;
        		else {
        			double slope = double(p[i].y-p[j].y)/double(p[i].x-p[j].x);
        			mp[slope]++;
        		} 
        	}
        	int tmaxs = 0;
        	for(auto x:mp){
        		tmaxs = max(tmaxs,x.second);
        	}
        	tmaxs += samepoint;
        	res = max(res,tmaxs);
        }
        return res;
    }
};