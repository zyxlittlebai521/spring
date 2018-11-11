/*
		filename:hash_table.cpp
		create by ��ѩ
		��C++ʵ��һ����ϣ��

		1��ʵ�����ù�ϣ��������
		2��ʵ�ֹ�ϣ��
		  2.1��ϣ��ʵ����һ��Node���飬Node��ÿ��Ԫ�����������֣�key��value,_pnext;
		  2.2�����ϣ����ʼ��С����Ϊ3,
		  2.3ʵ��resize()������ÿ�γ�������ʱ���¹�ϣ
		  2.4put()ʱ�����ж��Ƿ�isfull������fullʱ����resize���������򣬸��ݹ�ϣ���������������Ȼ�����
		 

*/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class Person
{
public:
	Person(int id = 0,const char*name ="\0"):_id(id)
	{
		strcpy(_name,name);
	}
	int getInd()const{return _id;}
	void show()
	{
		cout<<"id:"<<_id<<"  _name:"<<_name<<endl;
	}
private:
	int _id;
	char _name[20];
};


template <typename T>
class CHashFun//����hash����
{
public:
	CHashFun(int size):_bucketsize(size){}
	int GetHash(const T&val)
	{
		return val%_bucketsize;//hashֵ
	}
	void setBucketSize(int size)
	{
		_bucketsize = size;
	}
private:
	int _bucketsize;//����Ͱ����
};
template<typename K,typename V>
class CHashTable
{
public:
	CHashTable(int size = 3,double threshold = 0.75)
		:_size(size)
		,_threshold(threshold)
		,_use_size(0)
		,_hashfun(size)
	{
		pHashTable = new Node[size];
	}

	bool isfull()const
	{
		double load = _use_size*1.0/_size;
		cout<<"��ǰ��ϣ��ĳ��ȣ�"<<_size<<"�����ǣ�"<<load<<"        _threshold:"<<_threshold<<endl;
		//return (fabs( load-_threshold) < esp);
		return load >= _threshold;
	}
	//����ϣ��������ԭ����Ԫ��ȫ��Ҫ��ϴ
	void resize()
	{
		int size = hash_size(_size);//�õ��µ�hashֵ
		Node*mHashTable = new Node[size];
		_use_size = 0;
		_hashfun.setBucketSize(size);//

		for(int i=0;i < _size;++i)
		{
			Node*pcur = pHashTable[i]._pnext;
			while(pcur != NULL)
			{
				int index = _hashfun.GetHash(pcur->_key);
				if(mHashTable[index]._pnext == NULL)
				{
					mHashTable[index]._pnext = new Node(pcur->_key,pcur->_value);
					_use_size++;
				}
				else
				{
					Node*tmp = &mHashTable[index];
					while(tmp->_pnext != NULL)
					{
						tmp = tmp->_pnext;
					}
					tmp->_pnext = new Node(pcur->_key,pcur->_value);
				}
				pcur = pcur->_pnext;
			}
		}

		for(int j = 0;j < _size;++j)
		{
			Node*p = pHashTable[j]._pnext;
			Node*q = p;
			while(p != NULL)
			{
				q = p->_pnext;
				delete p;
				p = q;
			}
		}
		delete []pHashTable;
		pHashTable = mHashTable;
		_size = size;
	}

	void put(const K&key,const V&val)
	{
		if(isfull())
		{
			resize();
		}
		int hashIndex = _hashfun.GetHash(key);
		Node*pcur = pHashTable[hashIndex]._pnext;
		Node*p = pcur;
		if(pcur == NULL)
		{
			Node*tmp = new Node(key,val);
			pHashTable[hashIndex]._pnext = tmp;
			_use_size++;
			return ;
		}
		while(pcur != NULL)
		{
			if(pcur->_key == key)
			{
				pcur->_value = val;
				
				return ;
			}
			p = pcur;
			pcur = pcur->_pnext;
		}
		p->_pnext = new Node(key,val);
		
	}

	void remove(const K&key)
	{
		int index = _hashfun.GetHash(key);
		Node*pcur = pHashTable[index]._pnext;
		//Node*pcur = pHashTable[index];
		Node*tmp =  pcur;
		if(pcur != NULL)
		{
			while(pcur != NULL)
			{
				if(pcur->_key == key)
				{
					tmp->_pnext = pcur->_pnext;
					delete pcur;
					return ;
				}
				tmp = pcur;
				pcur = pcur->_pnext;
			}
			pcur = pHashTable[index]._pnext;
			if(pcur == NULL)
			{
				_use_size--;
			}
		}
		cout<<"û�и�key��Ԫ��"<<endl;
		return ;
	}

	V get(const K&key)
	{
		int index= _hashfun.GetHash(key);
		Node *pcur = pHashTable[index]._pnext;
		while(pcur != NULL)
		{
			if(pcur->_key == key)
			{
				return pcur->_value;
			}
			pcur = pcur->_pnext;
		}
		cout<<"û�д�key��Ԫ��"<<endl;
		return NULL;
	}
private:
	struct Node
	{
		Node(K key = K(),V val = V())
			:_key(key),_value(val),_pnext(NULL){}
		K _key;
		V _value;
		Node*_pnext;
	};


	static size_t hash_size(size_t num_elems)
	{
		static size_t sizes[]={3, 6, 23, 53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593,
			49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469,
			12582917, 25165843};

		const size_t nth_size  = sizeof(sizes)/sizeof(size_t)-1;
		for(size_t i = 0;i < nth_size;++i)
		{
			if(num_elems < sizes[i])
			return sizes[i];
		}
			return sizes[nth_size];
   
	}
	

	Node* pHashTable;
	double _threshold;
	int _size;
	int _use_size;
	CHashFun<K>_hashfun;
};

int main(int argc, char* argv[])
{
	
	CHashTable<int, Person> hashTable;
	hashTable.put(1, Person(1001, "zhang san"));
	hashTable.put(2, Person(1004, "gao yang"));
	hashTable.put(3, Person(1005, "three"));
	hashTable.put(4, Person(1007, "four"));
	hashTable.put(5, Person(1006, "five"));
	hashTable.put(6, Person(1008, "six"));
	hashTable.put(7, Person(1009, "seven"));
	hashTable.put(8, Person(1010, "eight"));
	hashTable.put(34, Person(1007, "four"));
	hashTable.put(10, Person(1006, "five"));
	hashTable.put(36, Person(1008, "six"));
	hashTable.put(37, Person(1009, "seven"));
	hashTable.put(38, Person(1010, "eight"));
	hashTable.put(71, Person(1009, "seven"));
	hashTable.put(82, Person(1010, "eight"));
	hashTable.put(324, Person(1007, "four"));
	hashTable.put(120, Person(1006, "five"));
	hashTable.put(336, Person(1008, "six"));
	hashTable.put(337, Person(1009, "seven"));
	hashTable.put(338, Person(1010, "eight"));
	hashTable.remove(1);
	Person p = hashTable.get(2);
	p.show();
	return 0;
}