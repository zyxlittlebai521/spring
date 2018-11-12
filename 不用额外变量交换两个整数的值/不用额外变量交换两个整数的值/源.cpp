/*
题目：不用额外的值交换两个整数的值
使用伪运算
  a = 4 = 100 b = 3 = 011
  a = a^b = 000
  b = a^b = 000 ^ 011 = 100
  a = a ^ b = 000 ^ 100 =011

  a = a + b = 4 + 3 = 7
  b = a - b = 7 -3 = 4
  a = a - b = 7 - 4 = 3

*/
#include <iostream>
using namespace std;
void fun1(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void fun2(int *a,int* b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}
void fun3(int &a,int& b)
{
	a = a + b;
	b = a - b;
	a = a-b;
}

int main()
{
	int a1 = 3,a2 = 3,a3 = 3;
	int b1 = 4,b2 = 4,b3 = 4;
	fun1(&a1,&b1);
	fun2(&a2,&b2);
	fun3(a3,b3);
	cout<<"a1 ="<<a1<<"  b1 = "<<b1<<endl;
	cout<<"a2 ="<<a2<<"  b2 = "<<b2<<endl;
	cout<<"a3 ="<<a3<<"  b3 = "<<b3<<endl;
	return 0;
}