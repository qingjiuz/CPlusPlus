#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<iostream>
using namespace std;

#include"string.h"

void stringTest1()
{
	self_string::string s1 = "hello world";
	cout << s1.c_str() << endl;

	const self_string::string s2 = "hello";
	cout << s2.c_str() << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		++s1[i];
	}
	cout << s1.c_str() << endl;

	for (size_t i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

}

void stringTest2()
{
	self_string::string s1 = "hello world";
	cout << s1.c_str() << endl;

	s1.push_back('#');
	s1.push_back('#');
	s1.push_back('#');
	cout << s1.c_str() << endl;


}

int main()
{
	stringTest2();

	return 0;
}
