/*
	2018.11.12 杨雪
	题目：实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作
	要求：pop，push，getMin操作的时间复杂度都是O（1）
	设计1：
	push：dataStack直接压入newdata，判断newdata与minStack栈顶元素大小
	                                newdata > minStack.top()，不压入
									newdata <= minStack.top(),newdata压入minStack栈顶
	pop:dataStack非空时直接出栈，newdata= dataStack.top();判断newdata与minStack栈顶元素大小
								 newdata = minStack.top(),minStack.pop();
								 newdata > minStack.top(),不进行操作
	getMin：minStack非空时直接出栈。


	设计2：
	push：dataStack直接压入newdata，判断newdata与minStack栈顶元素大小
	                           data = minStack.top();  newdata >data，minStack.push(data);
								newdata <= minStack.top(),newdata压入minStack栈顶
	pop:dataStack非空时直接出栈，minStack非空直接出栈

	getMin：minStack非空时直接出栈。


*/
#include <iostream>
#include <stack>
using namespace std;

class MyStack
{
	public:
	MyStack()
	{
		dataStack =  stack<int>();
		minStack =  stack<int>();
	}
	int MyPop1()
	{
		int data = 0;
		if(dataStack.empty()||minStack.empty())
		{
			return -1;
		}
		else
		{
			data = dataStack.top();
			dataStack.pop();
			if(data == minStack.top())
			{
				minStack.pop();
				return data;
			}
			else if(data > minStack.top())
			{
				return minStack.top();
			}
		}

	}
	
	void MyPush1(const int val)
	{
		dataStack.push(val);
		if(minStack.empty())
		{
			minStack.push(val);
		}
		else
		{
			if(val <= minStack.top())
			minStack.push(val);
		}
		return ;
	}
	//////////////////////////////////////设计2
	int MyPop2()
	{
		if(!dataStack.empty()&&!minStack.empty())
		{
			dataStack.pop();
			int data = minStack.top();
			minStack.pop();
			return data;
		}
		return -1;
	}
	
	void MyPush2(const int val)
	{
		dataStack.push(val);
		if(minStack.empty())
		{
			minStack.push(val);
			return ;
		}
		int data =  minStack.top();
		if(val >= data)
		{
			minStack.push(data);
		}
		else
		{
			minStack.push(val);
		}
		return ;
	}
	int getMin()
	{
		if(!minStack.empty())
		{
			return minStack.top();
		}
		return-1;
	}
	private:
	stack<int>dataStack;
	stack<int>minStack;
};

int main()
{
	//MyStack stack1;
	MyStack stack2;
	/*stack1.MyPush1(5);
	stack1.MyPush1(3);
	stack1.MyPush1(2);
	stack1.MyPush1(1);
	stack1.MyPush1(6);
	cout<<stack1.getMin()<<endl;
	cout<<stack1.MyPop1()<<endl;
	cout<<stack1.MyPop1()<<endl;
	cout<<stack1.MyPop1()<<endl;
	cout<<stack1.MyPop1()<<endl;
	cout<<stack1.MyPop1()<<endl;
	cout<<stack1.MyPop1()<<endl;
	cout<<stack1.MyPop1()<<endl;*/

	stack2.MyPush2(4);
	stack2.MyPush2(3);
	stack2.MyPush2(5);
	stack2.MyPush2(2);
	stack2.MyPush2(1);
	stack2.MyPush2(9);
	stack2.MyPush2(5);
	cout<<stack2.MyPop2()<<endl;
	cout<<stack2.MyPop2()<<endl;
	cout<<stack2.MyPop2()<<endl;
	cout<<stack2.MyPop2()<<endl;
	cout<<stack2.MyPop2()<<endl;
	cout<<stack2.MyPop2()<<endl;
	return  0;
}