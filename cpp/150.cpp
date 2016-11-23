class Solution {
public:
    int evalRPN(vector<string> &tokens) {
       for(auto tok:tokens){
       		if(tok[0]>='0'&&tok[0]<='9'||tok[0]=='-'&&tok.size()>1)
       			nums.push(stoi(tok));
       		else {
       			int x = nums.top();nums.pop();
       			int y = nums.top();nums.pop();
       			switch (tok[0]) {
       				case '+':
       					nums.push(y+x);
       					break;
       				case '-':
       					nums.push(y-x);
       					break;
       				case '*':
       					nums.push(y*x);
       					break;
       				case '/':
       					nums.push(y/x);
       					break;
       			}
       		}
       } 
       return nums.top();
    }
private:
	stack<int> nums;
};