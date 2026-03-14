#include<bits/stdc++.h>
using namespace std;

// Using single queue
class Stack {
public:
	queue<int> que;
	// Push element x onto stack.
	void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){ // Push ""n-1"" elements onto queue so the n th element will be in front
			que.push(que.front()); 
			que.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		que.pop();
	}

	// Get the top element.
	int top() {
		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return que.empty();
	}
};