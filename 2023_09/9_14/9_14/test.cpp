#pragma once
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1 = "+123";
	string s2 = "-123";
	string s3 = "1-23";

	size_t pos1 = s1.find_first_of("-+1234567890", 0);
	cout << pos1 << endl;


	return 0;
}