#pragma once
#include<assert.h>

namespace self_string
{
	class string
	{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;				// �������ַ�����С�ǲ�����'\0'��
			_str = new char[_capacity + 1];	// ����+1��Ϊ�˴�'\0'
			
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		char* c_str()
		{
			return _str;
		}

		char* c_str() const
		{
			return _str;
		}

		size_t size()
		{
			return _size;
		}

		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		// �޸�����
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];	// ͬ�ϵĹ��캯��һ��
				strcpy(tmp, _str);

				// ��Ϊһ��ʼ_capacity�ͱ�_size��һ���������ڵ�һ��β���ʱ�������������
				// ʵ�����Ѿ�����Խ����������ڶ���β������ʱ����Ҫ�ͷ�ԭ�ڴ��ʱ����Խ��
				// ��˳��ִ���
				// �˴��������_capacity��_size�����
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}

			_str[_size] = c;
			++_size;
			_str[_size] = '\0';
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}