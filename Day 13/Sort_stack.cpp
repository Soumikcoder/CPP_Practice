#include <bits/stdc++.h> 
void sortStack(stack<int> &stack)
{
	priority_queue<int,vector<int>,greater<int> > pq;
	while(!stack.empty()){
		pq.push(stack.top());
		stack.pop();
	}
	while(!pq.empty()){
		stack.push(pq.top());
		pq.pop();
	}
	// Write your code here
}