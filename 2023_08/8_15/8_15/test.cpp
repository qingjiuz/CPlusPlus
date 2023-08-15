#pragma once
#include<iostream>
using namespace std;

//class Date
//{
//public:
//	//��ʼ���б�
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	// ���������const���� -->  void Print(Date* const this)
//	void Print() const		// void Print(const Date* const this)
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	// һ�㶼����Ҫ�Լ�д���أ�ֱ��ʹ�ñ������Զ����ɵ�Ĭ��ȡ��ַ���ؾͿ���
//	Date* operator&()				// ���ص��Ƕ���ȡ��ַ
//	{
//		return this;
//	}
//
//	const Date* operator&() const	// ���ص���const���εĶ���ȡ��ַ
//	{
//		return this;
//	}
//
//private:
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//
//int main()
//{
//	Date d1(2023, 8, 15);
//	d1.Print();
//
//	const Date d2(2023, 8, 1);
//	d2.Print();
//
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//
//	return 0;
//}

////////////////////////////////////////////////////////////////
//��ʼ���б�

//class A
//{
//public:
//	A(int val)
//		: _val(val)
//	{}
//
//private:
//	int _val;
//};
//
//class B
//{
//public:
//	// ��ʼ���б�����ĳ�Ա�����λ��
//	B(int a, int b)	//�ڳ�ʼ���б��У�ÿ����Ա�������ֻ�ܳ���һ��
//		: _aobj(a)
//		, _ref(b)
//		,_n(b)
//	{}
//private:
//	//�����������������ʹ�ó�ʼ���б��ʼ����
//	A _aobj;		// û��Ĭ�Ϲ��캯�� --> ��û��ʹ���Դ����޲�Ĭ�Ϲ��� �� ȫȱʡĬ�Ϲ���
//	int& _ref;		// ����
//	const int _n;	// ��const����
//};

//class Stack
//{
//public:
//	// Ĭ�Ϲ��캯��
//	Stack(int capacity = 4)
//		: _Data((int*)malloc(sizeof(int) * capacity))
//		, _capacity(capacity)
//		,_size(0)
//	{
//		if (_Data == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		// ...
//	}
//
//	Stack(const Stack& st)
//	{
//		_Data = (int*)malloc(sizeof(int) * st._capacity);
//		if (_Data == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memcpy(_Data, st._Data, sizeof(int) * st._capacity);
//		_capacity = st._capacity;
//		_size = st._size;
//	}
//
//	~Stack()
//	{
//		free(_Data);
//		_Data = nullptr;
//	}
//
//private:
//	int* _Data;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue
//{
//public:
//	// �Լ������Զ������͵�Ĭ�Ϲ���
//	MyQueue()
//	{}
//
//	// ��ʼ���б�ȥ�����Զ������͵�Ĭ�Ϲ���
//	MyQueue(int capacity)
//		: _pushst(capacity)
//		, _popst(capacity)
//	{}
//
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//
//int main()
//{
//	MyQueue q1;			// capacity = 4
//	MyQueue q2(10);		// capacity = 10
//
//	return 0;
//}


//class A
//{
//public:
//	// ��ʼ��˳���ǳ�Ա���������е������������ʼ���б��˳���޹�
//	A(int a)
//		: _a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};
//
//int main()
//{
//	A aa(1);
//	aa.Print();		// 1 -858993460
//
//	return 0;
//}

//////////////////////////////////////////////// 
//��ʽ����ת��
//class A
//{
//public:
//	// ��explicit���ι��캯�����ֹ��ʽ����ת��
//	//explicit A(int a)
//	//	: _a(a)
//	//{}
//	
//	// ���ι��캯����û����explicit���Σ����������ת������
//	A(int a)
//		: _a(a)
//	{}
//
//
//	A(const A& a)
//	{
//		_a = a._a;
//	}
//
//	void Print()
//	{
//		cout << _a << endl;
//	}
//	
//private:
//	int _a;
//};
//
//int main()
//{
//	// Ŀǰ��Ϊ��������ʱ��������Ļ��������в�������
//
//	A aa1(1);	// ���캯��
//	A aa2 = 2;	// ��ʽ����ת��-->����ת�����Զ�������
//	// 2�ȹ���һ��A����ʱ����Ȼ�󿽱������aa2 --> ������̻ᱻ�Ż�����2ֱ�ӹ���
//
//	// error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��A &��
//	//A& aa3 = 3;
//
//	// 3����A����ʱ������ʱ������г����ԣ����ֻ�ܸ���const���εĶ���
//	const A& aa3 = 3;	
//
//	return 0;
//}

///////////////////////////////////////////////////////
// ������static���γ�Ա���� �� ��Ա����
//	��������д����˶��ٸ������

// 1. ����ȫ�ֱ���
// ���ƣ�ȫ�ֱ������κεط������޸�
//int _scount = 0;

//class A
//{
//public:
//	// ���캯��
//	A()
//	{
//		++_scount;
//	}
//
//	// �������캯��
//	A(const A& a)
//	{
//		++_scount;
//	}
//
//	// ��������
//	~A()
//	{
//		--_scount;
//	}
//
//private:
//	int _a;
//};


// 2. �����ڲ�������̬�ĳ�Ա����
//class A
//{
//public:
//	// ���캯��
//	A()
//	{
//		++_scount;
//	}
//
//	// �������캯��
//	A(const A& a)
//	{
//		++_scount;
//	}
//
//	// ��������
//	~A()
//	{
//		--_scount;
//	}
//
//	// ��ȡ�Ѵ����������
//	//int GetACount()		// int GetACount(A* const this)
//	static int GetACount()	// static int GetACount() -->	��������û����thisָ��
//	{
//		// ��̬���ܵ��÷Ǿ�̬ --> ԭ����û��thisָ��
//		//++_a1;
//
//		return _scount;
//	}
//
//	// �Ǿ�̬���Ե��þ�̬ --> �ڲ�������thisָ��Ĵ���
//	void func()
//	{
//		GetACount();
//	}
//
//private:
//	// ��Ա���� -- ����ÿһ������󣬴洢�ڶ�������
//	int _a1;
//	int _a2;
//
//	// ��̬��Ա���� -- �����࣬�����ÿ���������洢�ھ�̬��
//	// ���ڷ����޶��������ƣ��ⲿ�޷�ֱ�ӷ���
//	static int _scount;	// ע�⣺����ľ�̬��Ա��������������������Ҫ����������г�ʼ��
//};
//
//// ��̬��Ա��ʼ�� --> ��ȫ��λ�ò��ܶԾ�̬��Ա���ж���
//int A::_scount = 0;
//
//void func1()
//{
//	A aa1;
//	cout << __LINE__ << " : " << A::GetACount() << endl;
//}
//
//void func2()
//{
//	static A aa1;
//}
//
//
//int main()
//{
//	//A aa1;
//	//cout << __LINE__ << " : " << _scount << endl;
//	//A aa2;
//	//cout << __LINE__ << " : " << _scount << endl;
//	//func2();
//	//cout << __LINE__ << " : " << _scount << endl;
//	//func1();
//	//cout << __LINE__ << " : " << _scount << endl;
//
//	//A aa1;
//	// ��A::GetACount��: ���÷Ǿ�̬��Ա������Ҫһ������ -- û��static���κ���
//	//cout << __LINE__ << " : " << A::GetACount() << endl;
//
//	A aa1;
//	cout << __LINE__ << " : " << A::GetACount() << endl;
//	func1();
//	cout << __LINE__ << " : " << A::GetACount() << endl;
//	func2();
//	cout << __LINE__ << " : " << A::GetACount() << endl;
//
//
//	return 0;
//}

///////////////////////////////////////////////////////
// ���һ���ֻ࣬���� ջ ���� �� �ϴ�������

class A
{
public:
	// ջ�ϴ���һ������
	static A GetStackObj()
	{
		A aa;
		return aa;
	}

	// ���ϴ���һ������
	static A* GetHeapObj()
	{
		return new A;
	}

private:
	int _a = 1;
};

int main()
{
	A a1;				// ջ
	static A a2;		// ��̬��
	A* ptr = new A;		// ��

	A::GetStackObj();	// ջ
	A::GetHeapObj();	// ��

	return 0;
}
