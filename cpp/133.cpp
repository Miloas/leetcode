/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
        stack<UndirectedGraphNode*> st;
        st.push(node);
        mp[node] = new UndirectedGraphNode(node->label);
        while(!st.empty()){
        	auto cur = st.top();st.pop();
        	for(auto x:cur->neighbors){
        		if(!mp.count(x)){
        			mp[x]=new UndirectedGraphNode(x->label);
        			st.push(x);
        		}
        		m[cur]->neighbors.push_back(m[x]);
        	}
        }
        return mp[node];
    }
};