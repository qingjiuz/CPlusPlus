#include<iostream>

using std::cout;
using std::endl;

//�����ռ�
// ��c�����л�����ض��������
// ����ͷ�ļ��ڲ�����ʹ�ù��������������ڱ�д�����ʱ���ǲ����ٶ����
// c++�м����������ռ��ֹ��������ķ���
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

	//�����ռ��ǿ���Ƕ�׵�
	namespace N2
	{
		int rand = 2;
	}
}

//using namespace std;
//��仰�����˽����ڵ������ռ���չ����
//����ǿ��ܻ������������c�����ض��������
//��ˣ���仰��������ʹ��
//����Ҫ�õ����ڵĳ�Աʱ�����������¼��ַ�ʽ���

//1.ֱ��ʹ���������޶���
//printf("%d\n", N1::rand);

//2.ʹ��using�������ռ���ĳ����Ա����
//using std::cout;
//using std::endl;

//3.�����������ʹ��

int main()
{
	//����N1�����ռ����rand --> ʹ��"::"�������޶���
	//ע�⣺"::"ǰû�м��κ������ռ�����ʱ����ʺ������ȫ�ֱ���
	//printf("%d\n", N1::rand);
	//printf("%d\n", N1::N2::rand);

	//"<<"�������������
	//">>"������ȡ�����
	//���ƣ��Զ�ʶ����������
	//���ƣ����c����printf�����ܷ�����ѷ
	//��Ϊ����c���ԣ����Ҳ�������printfһ��ʹ��
	
	std::cin >> N1::N2::rand;

	cout << "hello world!" << endl;
	cout << N1::sum(2, 8) << '\n' << N1::N2::rand << endl;
	cout << 3.14 << endl;


	return 0;
}

