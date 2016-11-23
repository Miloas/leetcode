int dx[]={-1,0,1,0},
	dy[]={0,-1,0,1};
class Solution {
public:
	bool f(vector<vector<char>> &board,const char *word,int x,int y){
		if(board[x][y]!=*word++)return false;
		if(!*word)return true;
		board[x][y]=~board[x][y];
		for(int dir=0;dir<4;++dir){
			int xx=x+dx[dir],yy=y+dy[dir];
			if(xx>=0&&xx<board.size()&&yy>=0&&yy<board[0].size()&&f(board,word,xx,yy))
				return true;
		}
		board[x][y]=~board[x][y];
		return false;
	}
    bool exist(vector<vector<char> > &board, string word) {
    	for(int i=0;i<board.size();++i){
    		for(int j=0;j<board[0].size();++j){
    			if(f(board,word.c_str(),i,j))return true;
    		}
    	}
    	return false;
    }
};