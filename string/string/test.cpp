#pragma once
#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string s1;
//	string s2 = "hello world";
//	string s3("hello world");
//	cout << s1 << endl; //  (�յ�)
//	cout << s2 << endl;	// hello world
//	cout << s3 << endl; // hello world
//
//	string s4 = s2;
//	string s5(s2);
//	cout << s4 << endl; // hello world
//	cout << s5 << endl;	// hello world
//
//	string s6(10, 'x');	// xxxxxxxxxx
//	cout << s6 << endl;
//
//	string s7(s2, 6, s2.size());
//	cout << s7 << endl;	// world
//	string s9(s2, 6);
//	cout << s9 << endl;	// world
//
//	string s8("hello world", 4);
//	cout << s8 << endl;	// hell
//
//	
//
//	return 0;
//}

//int main()
//{
//	string s1("hello");
//	s1 += " world";
//	cout << s1 << endl;
//
//	s1.append("!!!");
//	cout << s1 << endl;
//
//	s1.push_back('x');
//	cout << s1 << endl;
//
//	s1.append("xxxxxxxx", 5);
//	cout << s1 << endl;
//
//
//	return 0;
//}

//int main()
//{
//	//string s1 = "hello world";
//	//cout << s1.size() << endl;		// 11
//	//cout << s1.length() << endl;	// 11
//	//cout << s1.max_size() << endl;	// ���ȶ�
//
//	//cout << s1.capacity() << endl;	// vs��15	g++��11
//
//	string s1 = "hello world";
//
//	//s1.reserve(100);
//	//cout << s1.size() << endl;
//	//cout << s1.capacity() << endl;
//
//	//s1.clear();
//	//s1.reserve(0);
//	//cout << s1.size() << endl;
//	//cout << s1.capacity() << endl;
//
//	//s1.reserve(100);	// ����    �ı�capacity
//	//cout << s1.size() << endl;
//	//cout << s1.capacity() << endl;
//
//	//s1.resize(10);		// �ı�size
//	//cout << s1.size() << endl;
//	//cout << s1.capacity() << endl;
//
//	//cout << s1.empty() << endl;
//	//s1.clear();
//	//cout << s1.empty() << endl;
//
//	s1.reserve(100);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	s1.shrink_to_fit();
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	return 0;
//}

//int main()
//{
//	//string s1 = "hello world";
//	//s1[0] = 'x';
//	//cout << s1 << endl;
//
//	//s1.at(1) = 'x';
//	//cout << s1 << endl;
//
//	//cout << s1.back() << endl;
//	//cout << s1.front() << endl;
//
//	// ������
//	//string::iterator it = s1.begin();
//	//while (it != s1.end())
//	//{
//	//	cout << *it;
//	//	++it;
//	//}
//	//cout << endl;
//
//	//for (auto& ch : s1)
//	//{
//	//	cout << ++ch;
//	//}
//	//cout << endl;
//
//	//reverse(s1.begin(), s1.end());
//	//cout << s1 << endl;
//
//	string s1 = "hello world";
//
//	// Խ�����
//	//s1[20];		// ���Լ��
//	//s1.at(20);	// ���쳣
//
//	return 0;
//}

int main()
{
	string s1 = "hello world";

	s1 += "xxx";
	cout << s1 << endl;

	s1.append(10, 'y');
	cout << s1 << endl;

	s1.push_back('!');
	cout << s1 << endl;

	return 0;
}
