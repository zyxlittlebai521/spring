#include <string>
#include <iostream>
using namespace std;
/*
 * 2018.11.12 ��ѩ
	����һ����������дһ���㷨�������ת��Ϊʮ�������������ڸ�����������ͨ��ʹ�� �������� ������

ע��:

    ʮ��������������ĸ(a-f)��������Сд��
    ʮ�������ַ����в��ܰ��������ǰ���㡣���Ҫת������Ϊ0����ô�Ե����ַ�'0'����ʾ���������������ʮ�������ַ����еĵ�һ���ַ���������0�ַ��� 
    ��������ȷ����32λ�з���������Χ�ڡ�

	Ҫ��һ��ʮ������ת��Ϊʮ�������������������������Ǹ�������ֻ��Ҫ��������Ʊ�ʾÿ��λ�ֳ�һ����Ԫ������ȡ�����������λ�������������ʮ����������0~f֮���������һ��ӳ�伴�ɡ�Ҫ��ÿ��λȡ��Ҳ�ܼ򵥣���0xf����AND���㼴�ɡ�
��C++�У��������߼���λ��Ҳ����˵�����ֺ��油0�������������������λ��Ҳ��������ಹ����λ(������0��������1
--------------------- 
���ߣ���ܺ�Ц�� 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/hy971216/article/details/80724302 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
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
