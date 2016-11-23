int dx[]={0,1,0,-1},
    dy[]={1,0,-1,0};
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if(!n)return res;
        res.assign(n,vector<int>(n,0));
        f(n,0,0,1,0);
        return res;
    }
    void f(int n,int x,int y,int i,int lastdir){
        if(res[x][y]!=0)return;
        res[x][y]=i;
        for(int j=0;j<4;++j){
            int xx=x+dx[(lastdir+j)%4],yy=y+dy[(lastdir+j)%4];
            if(xx>=0&&xx<n&&yy>=0&&yy<n)
                f(n,xx,yy,i+1,(lastdir+j)%4);
        }
    }
private:
    vector<vector<int>> res;
};