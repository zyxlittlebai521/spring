/*
	2018.11.12 ��ѩ
	��Ŀ��ʵ��һ�������ջ����ʵ��ջ�Ļ������ܵĻ����ϣ���ʵ�ַ���ջ����СԪ�صĲ���
	Ҫ��pop��push��getMin������ʱ�临�Ӷȶ���O��1��
	���1��
	push��dataStackֱ��ѹ��newdata���ж�newdata��minStackջ��Ԫ�ش�С
	                                newdata > minStack.top()����ѹ��
									newdata <= minStack.top(),newdataѹ��minStackջ��
	pop:dataStack�ǿ�ʱֱ�ӳ�ջ��newdata= dataStack.top();�ж�newdata��minStackջ��Ԫ�ش�С
								 newdata = minStack.top(),minStack.pop();
								 newdata > minStack.top(),�����в���
	getMin��minStack�ǿ�ʱֱ�ӳ�ջ��


	���2��
	push��dataStackֱ��ѹ��newdata���ж�newdata��minStackջ��Ԫ�ش�С
	                           data = minStack.top();  newdata >data��minStack.push(data);
								newdata <= minStack.top(),newdataѹ��minStackջ��
	pop:dataStack�ǿ�ʱֱ�ӳ�ջ��minStack�ǿ�ֱ�ӳ�ջ

	getMin��minStack�ǿ�ʱֱ�ӳ�ջ��


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
	//////////////////////////////////////���2
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