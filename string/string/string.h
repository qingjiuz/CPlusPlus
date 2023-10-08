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
			_capacity = _size;				// 容量和字符串大小是不计算'\0'的
			_str = new char[_capacity + 1];	// 这里+1是为了存'\0'
			
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

		// 修改容量
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];	// 同上的构造函数一样
				strcpy(tmp, _str);

				// 因为一开始_capacity就比_size多一个，导致在第一次尾插的时候可以正常运行
				// 实际上已经出现越界的情况，令第二次尾插扩容时，需要释放原内存的时候有越界
				// 因此出现错误。
				// 此错误出现在_capacity和_size不相等
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