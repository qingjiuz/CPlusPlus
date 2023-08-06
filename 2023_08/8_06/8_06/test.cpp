#include<iostream>

using std::cout;
using std::endl;

//命名空间
// 在c语言中会存在重定义的问题
// 例如头文件内部定义使用过的命名，我们在编写程序的时候是不能再定义的
// c++中加入了命名空间防止这类问题的发生
//namespace


namespace N1
{
	int rand = 1;
	
	int sum(int x, int y)
	{
		return x + y;
	}

	struct Node
	{
		int data;
		struct Node* next;
	};

	//命名空间是可以嵌套的
	namespace N2
	{
		int rand = 2;
	}
}

//using namespace std;
//这句话代表了将库内的命名空间域展开了
//后果是可能会出现类似上述c语言重定义的问题
//因此，这句话不能随意使用
//当需要用到库内的成员时，可以有以下几种方式解决

//1.直接使用作用域限定符
//printf("%d\n", N1::rand);

//2.使用using将命名空间中某个成员引入
//using std::cout;
//using std::endl;

//3.上面两点配合使用

int main()
{
	//访问N1命名空间域的rand --> 使用"::"作用域限定符
	//注意："::"前没有加任何命名空间域名时会访问函数外的全局变量
	//printf("%d\n", N1::rand);
	//printf("%d\n", N1::N2::rand);

	//"<<"：流插入运算符
	//">>"：流提取运算符
	//优势：自动识别数据类型
	//劣势：相比c语言printf的性能方面略逊
	//因为兼容c语言，因此也可以配合printf一起使用
	
	std::cin >> N1::N2::rand;

	cout << "hello world!" << endl;
	cout << N1::sum(2, 8) << '\n' << N1::N2::rand << endl;
	cout << 3.14 << endl;


	return 0;
}

