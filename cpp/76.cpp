class Solution {
public:
    string minWindow(string S, string T) {
    	if(S.empty()||T.empty())return "";
		int require[128]={0},n=T.size(),wset[128]={0};
		for(int i=0;i<n;++i)
			require[T[i]]++;
		int s=0,t=0,num=0,len=S.size(),idx=0;
		bool ok=false;
		for(;;){
			while(t<S.size()&&num<n){
				if(wset[S[t]]++<require[S[t++]]){
					num++;
				}
				if(num==n)ok=true;
			}
			if(num<n)break;
			if(len>t-s){
				idx=s;
				len=t-s;
			}
			if(--wset[S[s]]<require[S[s++]])num--;
		}
		return ok?S.substr(idx,len):"";
    }
};