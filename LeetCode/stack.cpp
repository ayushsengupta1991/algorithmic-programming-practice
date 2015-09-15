#include<stack>
#include<iostream>
using namespace std;
class MinStack {
	stack<int> minStack;
	stack<int> Stack;
public:
	
	void push(int x) {
		
		Stack.push(x);
		if(minStack.size()==0)
			minStack.push(x);
		if(x<=Stack.top())
			minStack.push(x);
	}
	
	void pop()
	{
		
		int x=Stack.top();
		if(x==minStack.top())
			minStack.pop();
		Stack.pop();
		
	}
	
	int top() {
		
		return Stack.top();
	}
	
	int getMin() {
		
		return minStack.top();
		
	}
};
int main()
{
	Minstack m;
	
	return 0;
}
