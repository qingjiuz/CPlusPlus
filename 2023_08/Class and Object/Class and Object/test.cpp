#pragma once
#include<iostream>
using namespace std;

//class A
//{
//	//��Ҫע�����Ȩ�޵Ŀ���
//public:
//	//��Ҫע��������λ��
//	void Add();
//
//	void Print()
//	{
//		cout << "Printf()" << endl;	// ��Ȼ�����thisָ���ǿյģ�����û�жԿ�ָ�������
//	}
//
//	void Print(int a, int b)
//	{
//		cout << _a << endl;			// �Դ���Ŀ�ָ��this�����˽�����-->���д���
//	}
//
//
//private:
//	int _a;
//	int _b;
//};
//
////�����ⶨ�庯��
//void A::Add()
//{
//	cout << _a + _b << endl;
//}

//int main()
//{
//	//A a;
//	//a.Print();
//	//����Ȩ�޵�����-->ʹ��ʱֻ�ܷ���public�ĳ�Ա
//	//a.a = 10;
//	//a.b = 20;
//	//cout << a.a << endl;
//	//cout << a.b << endl;
//
//	//////////////////////////////////////////////////////////
//	//A* a;
//	//a = nullptr;
//
//	//// a����ʱû�з��������ã�����������������ڱ�������ж����������
//	//a->Print();			
//	//a->Print(10, 20);
//
//	return 0;
//}

//////////////////////////////////////
////����һ�����׵�ջ
//typedef int DataType;
//
//class Stack
//{
//public:
//	void Init(int capacity = 4)
//	{
//		_data = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (_data == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//
//		_capacity = 4;
//		_size = 0;
//	}
//
//	void Push(DataType x)
//	{
//		//�������
//		//...
//
//		_data[_size++] = x;
//	}
//
//	void Pop()
//	{
//		//...
//
//		_size--;
//	}
//
//	void Distroy()
//	{
//		free(_data);
//		_data = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//	void Print()
//	{
//		for (int i = 0; i < _size; i++)
//		{
//			cout << _data[i] << " ";
//		}
//		cout << endl;
//	}
//
//private:
//	//Ϊ�����������Ա����ǰ����ü���"_XXXX"����"mXXXX"����Ϊ���κͳ�Ա����������
//	DataType* _data;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Print();
//	st.Pop();
//	st.Pop();
//	st.Print();
//
//	st.Distroy();
//	return 0;
//}

////////////////////////////////////////////
//�г�Ա����
//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << endl;
//	}
//
//private:
//	char _a;
//	int _b;
//};
//
////����
//class B
//{};
//
////ֻ�г�Ա����
//class C
//{
//	void test()
//	{}
//};
//
//int main()
//{
//	// ������Ĵ�СҲ��Ҫע���ڴ����
//	cout << sizeof(A) << endl;	// 8 Byte
//
//	// ��������û�г�Ա����--�� ���� ���� ֻ�г�Ա���� ʱ��Ҳ��ռ��1Byte��Ϊռλ
//	cout << sizeof(B) << endl;	// 1 Byte
//	cout << sizeof(C) << endl;	// 1 Byte
//
//	return 0;
//}

///////////////////////////////////////////////
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// ʵ���ϻ���һ��thisָ�봫�룬�ɱ��������д���
//	//void print(Date* this)
//	void Print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//
//private:
//	int _year;	// ��
//	int _month;	// ��
//	int _day;	// ��
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2023, 8, 11);
//	
//	//���������Լ���thisָ��
//	//d1.Print(&d1);
//	d1.Print();
//
//	return 0;
//}

///////////////////////////////////////
//����һ�����׵�ջ----���캯�� �� ��������
//typedef int DataType;
//
//class Stack
//{
//public:
//	//���캯��--�����������û�з���ֵ(Ҳ������void)�ĺ���
//	Stack(int capacity = 4)
//	{
//		_data = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (_data == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//
//		_capacity = 4;
//		_size = 0;
//	}
//
//	//��������--���������ĺ�����ǰ�����"~"�ĺ���
//	~Stack()
//	{
//		free(_data);
//		_data = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//	void Push(DataType x)
//	{
//		//�������
//		//...
//
//		_data[_size++] = x;
//	}
//
//	void Pop()
//	{
//		//...
//
//		_size--;
//	}
//
//	void Print()
//	{
//		for (int i = 0; i < _size; i++)
//		{
//			cout << _data[i] << " ";
//		}
//		cout << endl;
//	}
//
//private:
//	DataType* _data;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	// ���û����ʾ���幹�����������
//	// ϵͳ���Զ�����һ���޲ε�Ĭ�Ϲ��캯�������û�����ʾ�����򲻻��Զ�����
//	// �Լ�ϵͳ���Զ�����Ĭ�ϵ��������������������أ�
//	Stack st1;
//	Stack st2(10);
//	// ���캯�������˳�ʼ������Ϊ�ڶ���ʵ����ʱ���������Զ����ö�Ӧ�Ĺ��캯��
//	//st1.Init();
//
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//	st1.Print();
//
//	// �������������˶������������������ʱ���Զ�������������
//	//st1.Distroy();
//	//st2.Distroy();
//	return 0;
//}

//////////////////////////////////////////////
//���캯�������أ�
class Date
{
public:
	// �޲�
	//Date()
	//{
	//	_year = 1;
	//	_month = 1;
	//	_day = 1;
	//}

	// ����
	//Date(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	// ��ȱʡ����-->>��ȱʡ������ʵ�ʵĹ������޲γ�ʼ���Ĺ��ܼ���һ��
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}


	void Print()
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}

private:
	int _year;	// ��
	int _month;	// ��
	int _day;	// ��
};

int main()
{
	// һ������£����������ͳ�Ա����Ҫ�Լ�д���캯��
	// ��ֻ���Զ������ͳ�Աʱ�����Կ���ʹ��ϵͳĬ�ϵĹ��캯��

	Date d1(2023, 8, 12);
	Date d2;				//���޲κʹ�ȱʡ�����Ĺ��캯��ͬʱ����ʱ�ᱨ��

	d1.Print();
	d2.Print();

	//Date d3();	// ʵ���ϻᱻ��������Ϊ�Ǻ��������������ͨ���޲δ�������ʱ���ܼ�����

	// Ĭ�ϵĹ��캯��������
	// û����ʾ���幹�캯��ʱ��ϵͳ���Զ�����һ���޲ε�Ĭ�Ϲ��캯��
	// ʹ��Ĭ�ϵĹ��캯��ʱ���������Ͳ�������
	// �Զ������ͻ�ȥ�������Ĺ��캯��
	//Date d4;
	//d4.Print();	//����Ľ���ǣ�-858993460--858993460--858993460

	return 0;
}

