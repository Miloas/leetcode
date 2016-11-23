class Solution {
public:
	typedef pair<int,int> pii;
	void dfs(vector<vector<char>> &board,bool fvck,int x,int y){
		stack<pii> st;
		st.push(make_pair(x,y));
		while(!st.empty()){
			int x = st.top().first,
				y = st.top().second;
			st.pop();
			if(vis[x][y]||board[x][y]=='X')continue;
			vis[x][y]=true;
			if(fvck)board[x][y]='X';
			if(x+1<m) st.push(make_pair(x+1,y));	
			if(y+1<n) st.push(make_pair(x,y+1));	
			if(x>=1)  st.push(make_pair(x-1,y));	
			if(y>=1)  st.push(make_pair(x,y-1));	
		}
	}

    void solve(vector<vector<char>> &board) {
    	if(board.empty()||board[0].empty())return;
        m=board.size(),n=board[0].size();
        vis.assign(m+1,vector<bool>(n+1,false)); 
        for(int i=0;i<n;++i){
        	if(!vis[0][i]&&board[0][i]=='O')dfs(board,false,0,i);
        	if(!vis[m-1][i]&&board[m-1][i]=='O')dfs(board,false,m-1,i);
        }
        for(int i=0;i<m;++i){
        	if(!vis[i][0]&&board[i][0]=='O')dfs(board,false,i,0);
        	if(!vis[i][n-1]&&board[i][n-1]=='O')dfs(board,false,i,n-1);
        }

        for(int i=0;i<m;++i)
        	for(int j=0;j<n;++j)if(board[i][j]=='O'&&!vis[i][j])
        		dfs(board,true,i,j);
    }
private:
	vector<vector<bool>> vis;
	int m,n;
};