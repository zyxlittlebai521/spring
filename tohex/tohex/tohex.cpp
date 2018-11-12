#include <string>
#include <iostream>
using namespace std;
/*
 * 2018.11.12 杨雪
	给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。

注意:

    十六进制中所有字母(a-f)都必须是小写。
    十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
    给定的数确保在32位有符号整数范围内。

	要将一个十进制数转换为十六进制数，不管其是正数还是负数，都只需要将其二进制表示每四位分成一个单元，将其取出后计算这四位二进制数代表的十进制数，与0~f之间的数字做一个映射即可。要把每四位取出也很简单，与0xf进行AND运算即可。
在C++中，左移是逻辑移位，也就是说在数字后面补0，右移运算符是算术移位，也就是在左侧补符号位(正数补0，负数补1
--------------------- 
作者：会很好笑诶 
来源：CSDN 
原文：https://blog.csdn.net/hy971216/article/details/80724302 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
string tohex(int num)
{
	string str;
	char hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	if(num == 0)return "0";
	while(num && str.size()<8)
	{
		str = hex[num&0xf]+str;
		num = num>>4;
	}
	cout<<str.size()<<endl;;
	return str;
	
}
string toTWO(int num)
{
	char two[] = {'0','1'};
	if(num == 0)return "0";
	string str;
	while(num&&str.size()<32)
	{
		str = two[num&1]+str;
		num = num>>1;
	}
	return str;
}
int main()
{
	cout<<tohex(0)<<endl;
	cout<<tohex(26)<<endl;
	cout<<tohex(-26)<<endl;
	cout<<tohex(294967296)<<endl;
	cout<<"****************************************"<<endl;
	cout<<toTWO(0)<<endl;
	cout<<toTWO(26)<<endl;
	cout<<toTWO(-26)<<endl;
	cout<<toTWO(294967296)<<endl;
	return 0;
}
