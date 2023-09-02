#pragma once
#include<iostream>
using namespace std;


// ��̬�ڴ����룺new��delete
class A
{
public:
	A(int a = 1, int b = 2)
		: _a(a)
		, _b(b)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
	int _b;
};

// new�ļ����÷�
// ע����Ҫ���deleteʹ��
// ��Ҫ��malloc��calloc��realloc��free���ʹ��
//int main()
//{
//	//int* a1 = new int(20);
//	//cout << *a1 << endl;
//	//delete a1;
//
//	//int* a2 = new int(1);
//	//cout << *a2 << endl;
//	//delete a2;
//
//	int* a = new int[10] {0};
//	delete[] a;
//
//	A* aa = new A;
//	delete aa;
//
//	A* aa2 = new A(10, 20);
//	delete aa2;
//
//	A* pa = new A[10]{ 1,2,3,4 };
//	delete[] pa;
//
//	A* pa2 = new A[4]{ A(1,2), A(2,3), A(3,4), A(4,5)};
//	delete[] pa2;
//
//	return 0;
//}

//int main()
//{
//	// new��delete �� malloc��free ��Ȼʵ���ô���û��ʲô����
//	// ������ǰ�����Զ������ͻ���ù��캯������������
//
//	int* p1 = (int*)operator new(sizeof(int));
//	operator delete(p1);
//	int* pp1 = new int;
//	delete pp1;
//
//	// ˳��
//	// new�����ռ� + ���캯��
//	// new --> operator new --> malloc --> ���캯��
//	// delete���������� + �ͷſռ�
//	// delete --> �������� --> operator delete --> free
//	A* p2 = (A*)operator new(sizeof(A));
//	operator delete(p2);
//	A* pp2 = new A(1, 2);
//	delete pp2;
//
//	return 0;
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_array = new DataType[capacity];
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	~Stack()
//	{
//		delete _array;
//		_capacity = 0;
//		_size = 0;
//	}
//
//private:
//	DataType* _array;
//	int _size;
//	int _capacity;
//};

//int main()
//{
//	// ����������Դ���̬�ڴ�����ʧ�ܣ�һ���ʹ�����쳣
//	// ���������쳣��ȡ��ʵ��
//	try
//	{
//		// ����ڴ�����ʧ�ܣ����׳��쳣
//		Stack* st1 = new Stack;
//		delete st1;
//	}
//	catch (const exception& e)
//	{
//		// ��ȡ�쳣���ڴ˴�ӡ
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	// �����paָ�����A���һ��ռ䣬������ʵ���������Ķ���
//	A* pa = (A*)malloc(sizeof(A));
//	// ��ʾ���ù��캯��
//	new(pa)A(10, 20);
//
//	// ����������������ܶ�pa�����ͷ�
//	pa->~A();
//	free(pa);
//
//	return 0;
//}



///////////////////////////////////////////////////////////////////////////////
// ģ��

// ���ͱ��
// ����ģ��

//template<typename T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.1, d = 2.2;
//	char e = 'a', f = 'b';
//
//	Swap(a, b);
//	Swap(c, d);
//	Swap(e, f);
//
//	return 0;
//}

//template<class T1, class T2>
//T1 func(T1& x, T2& y)
//{
//	cout << x << " " << y << endl;
//	return x;
//}
//
//int main()
//{
//	int a = 1;
//	double b = 2.2;
//
//	int c = func(a, b);
//	cout << c << endl;
//
//	return 0;
//}

//template<class T>
//T add(const T& a, const T& b)
//{
//	return a + b;
//}
//
//template<class T>
//T* Alloc(int capacity = 4)
//{
//	return new T[capacity];
//}

//int main()
//{
//	int a1 = 1, a2 = 2;
//	double b1 = 1.1, b2 = 2.2;
//	cout << add(a1, a2) << endl;
//	cout << add(b1, b2) << endl;
//
//	// ע��ģ�����͵��������Լ����ε�����
//	// ���ﴫ��ʱҪע�⣬ǿ������ת����������ʱ����--> ���г���--> ��Ҫ��const
//	cout << add((double)a1, b1) << endl;
//	cout << add(a1, (int)b1) << endl;
//
//	// ��ʾʵ����--> ʹ��ָ������ʵ����
//	cout << add<int>(a1, b1) << endl;
//	cout << add<double>(a1, b1) << endl;
//
//	// �������ͱ����������Լ��ƣ�ֻ����ʾʵ����
//	int* ptr = Alloc<int>(4);
//
//	return 0;
//}

// ��ģ��
// ��ģ����Դ�����ǰʹ�õ�typedef���÷�--> �����ֶ��������ͣ����Ӷ�̬

template<class T>
class Stack
{
public:
	Stack(int capacity = 4);
	//{
	//	_array = new T[capacity];
	//	_capacity = capacity;
	//	_size = 0;
	//}

	~Stack()
	{
		delete _array;
		_capacity = 0;
		_size = 0;
	}

private:
	T* _array;
	int _size;
	int _capacity;
};

// һ�㲻����ֿ�����
// Stack<T> �������Stack���캯��������
template<class T>
Stack<T>::Stack(int capacity)
{
	_array = new T[capacity];
	_capacity = capacity;
	_size = 0;
}

// ��ͨ�ࣺ������������һ����
// ��ģ�壺����������������
int main()
{
	// Stack	  ���������
	// Stack<int> ���������
	Stack<int> st1;
	Stack<double> st2;

	return 0;
}
