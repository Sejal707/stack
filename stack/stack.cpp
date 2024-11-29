#include<iostream>
using namespace std;
class StackOverFlow :public exception {};
class StackUnderFlow :public exception {};
template <class T>
class stack
{
	T* stk;
	int top = -1;
	int size;
public:
	stack(int x)
	{
		size = x;
		stk = new T[size];
	}
	void push(T x)
	{
		if (top == size - 1)
			throw StackOverFlow();
		top++;
		stk[top] = x;
		cout << "Pushed " << x << " to stack." << endl;
	}
	T pop()
	{
		if (top == -1)
			throw StackUnderFlow();
		cout << "Popped " << stk[top] << " from stack." << endl;
		return stk[top--];
	}
};
int main()
{
	try {
		stack <int> s1(3);
		s1.push(1);
		s1.push(2);
		s1.push(3);
		s1.push(4);
		s1.pop();
	}
	catch (StackOverFlow e)
	{
		cout << "Stack Overflow!" << endl;
	}
	catch (StackUnderFlow e)
	{
		cout << "Stack Underflow!" << endl;
	}
	try
	{
		stack<char>s2(2);
		s2.push('a');
		s2.pop();
		s2.pop();
	}
	catch (StackOverFlow e)
	{
		cout << "Stack Overflow!" << endl;
	}
	catch (StackUnderFlow e)
	{
		cout << "Stack Underflow!" << endl;
	}
}