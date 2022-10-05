// stack_two_queue
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Stack
{
	queue<T> q1,q2;

public:
	void push(T x)
	{
		q1.push(x);
	}
	void pop()
	{
		if (q1.empty())
		{
			return;
		}
		while(q1.size()>1)
		{
			T element=q1.front();
			q2.push(element);
			q1.pop();
		}
		q1.pop();
		swap(q1,q2);
	}
	int top()
	{
		while(q1.size()>1)
		{
			T element=q1.front();
			q2.push(element);
			q1.pop(); 
		}
	}
	
};
int main()
{
	int
}