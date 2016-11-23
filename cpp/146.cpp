class LRUCache{
public:
    LRUCache(int capacity):c(capacity),fraquent(0) {} 
    
    int get(int key) {
       if(ump.count(key)){
     		int _key=ump[key].second;
     		ump[key].second=++fraquent;
       		mp.erase(_key);
       		mp[fraquent]=key;
	       	return ump[key].first;
       }
       return -1; 
    }

    void _insert(int key,int value){
		ump[key]=make_pair(value,++fraquent);
		mp[fraquent]=key;
    }
    
    void set(int key, int value) {
       if(!ump.count(key)){
       		if(c>0){
       			_insert(key,value);
       			c--;
       		}
       		else {
       			int _key=(*mp.begin()).second;mp.erase(mp.begin());
       			ump.erase(_key);
       			_insert(key,value);
       		}
       } 
       else{
       		int _key=ump[key].second;
       		mp.erase(_key);
       		_insert(key,value);
       }
    }
 private:
 	typedef pair<int,int> pii;
 	int c;
 	int fraquent;
 	unordered_map<int,pii> ump;
 	map<int,int> mp;
};