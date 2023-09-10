#pragma once
#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string s1;
//	string s2 = "hello world";
//	string s3("hello world");
//	cout << s1 << endl; //  (空的)
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
//	//cout << s1.max_size() << endl;	// 不稳定
//
//	//cout << s1.capacity() << endl;	// vs：15	g++：11
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
//	//s1.reserve(100);	// 保留    改变capacity
//	//cout << s1.size() << endl;
//	//cout << s1.capacity() << endl;
//
//	//s1.resize(10);		// 改变size
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
//	// 迭代器
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
//	// 越界访问
//	//s1[20];		// 断言检查
//	//s1.at(20);	// 抛异常
//
//	return 0;
//}

//int main()
//{
//	string s1 = "hello world";
//
//	s1 += "xxx";
//	cout << s1 << endl;
//
//	s1.append(10, 'y');
//	cout << s1 << endl;
//
//	s1.push_back('!');
//	cout << s1 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1 = "hello world";
//	cout << s1 << endl;
//
//	//s1.assign("xxxxxxx");
//	//cout << s1 << endl;
//
//	//s1 = "xxxxxx";
//	//cout << s1 << endl;
//
//	//s1.insert(5, "abcdefg", 3, 2);
//	//cout << s1 << endl;
//
//	//s1.erase(0, 1);
//	//cout << s1 << endl;
//
//	//s1.erase(s1.begin(), s1.end());
//	//cout << s1 << endl;
//
//	s1.replace(5, 1, "xxx");
//	cout << s1 << endl;
//
//	return 0;
//}

//int main()
//{
//	string url = "https://message.bilibili.com/?spm_id_from=333.1007.0.0#/reply";
//
//	string protocol, domain, uri;
//
//	size_t pos1 = url.find("://");
//	if (pos1 != string::npos)
//	{
//		protocol = url.substr(0, pos1);
//	}
//
//	size_t pos2 = url.find("/", pos1 + 3);
//	if (pos2 != string::npos)
//	{
//		domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
//		uri = url.substr(pos2 + 1);
//	}
//	cout << protocol << endl;
//	cout << domain << endl;
//	cout << uri << endl;
//
//	return 0;
//}


//int main()
//{
//	string s1 = "hello world";
//
//	//cout << s1 << endl;			// string类
//	//cout << s1.c_str() << endl;	// string转成char*
//
//	cout << s1 << endl;
//	size_t found = s1.find_first_of("l");
//	while (found != string::npos)
//	{
//		s1[found] = '*';
//		found = s1.find_first_of("l", found + 1);
//	}
//	cout << s1 << endl;
//
//	return 0;
//}

//int main()
//{
//	//string s1 = "hello ";
//	//string s2 = "world";
//	//cout << s1 + s2 << endl;
//
//	return 0;
//}

int main()
{
	string s1;
	string s2;

	// 正常的cin读取到空格就会停止
	// 假如输入 “hello world”
	cin >> s1;
	cout << s1 << endl;		// hello
	cin >> s2;
	cout << s2 << endl;		// world

	// 提取一行的字符串，包括空格
	getline(cin, s1);	// getline(cin, s1, 'o'); --> 最后可以自行选择读取到某个字符停止
	cout << s1 << endl;

	return 0;
}
