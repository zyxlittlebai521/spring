/*
		filename:hash_table.cpp
		create by 杨雪
		用C++实现一个哈希表

		1、实现设置哈希函数的类
		2、实现哈希表
		  2.1哈希表实现用一个Node数组，Node的每个元素有三个部分，key，value,_pnext;
		  2.2构造哈希表，初始大小设置为3,
		  2.3实现resize()函数，每次超出负载时重新哈希
		  2.4put()时首先判断是否isfull（）。full时调用resize（），否则，根据哈希函数算出它的索引然后插入
		 

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
class CHashFun//设置hash函数
{
public:
	CHashFun(int size):_bucketsize(size){}
	int GetHash(const T&val)
	{
		return val%_bucketsize;//hash值
	}
	void setBucketSize(int size)
	{
		_bucketsize = size;
	}
private:
	int _bucketsize;//设置桶长度
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
		cout<<"当前哈希表的长度："<<_size<<"负载是："<<load<<"        _threshold:"<<_threshold<<endl;
		//return (fabs( load-_threshold) < esp);
		return load >= _threshold;
	}
	//当哈希表增长，原来的元素全部要冲洗
	void resize()
	{
		int size = hash_size(_size);//得到新的hash值
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
		cout<<"没有该key的元素"<<endl;
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
		cout<<"没有此key的元素"<<endl;
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