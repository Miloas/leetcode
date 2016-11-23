class MinStack {
public:
    void push(int x) {
       if(b.empty() || x <= b.top()) 
       		b.push(x);
       	a.push(x);
    }

    void pop() {
       if(a.top() == b.top())
       		b.pop();
       	a.pop(); 
    }

    int top() {
       return a.top(); 
    }

    int getMin() {
       return b.top(); 
    }
private:
	stack<int> a, b;
};