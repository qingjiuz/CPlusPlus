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

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, size_t n, char c)
		{
			assert(pos < _size);
			
			if (_size + n > _capacity)
			{
				reserve(_size + n);
			}

			size_t end = _size;
			// pos可以为0 --> 因为end类型为size_t --> 没有负数
			// 当end--到-1时，因为size_t没有负数，因此为整数的最大值，默认字符串不会有这么长
			// 所以可以利用这个特性作限制条件
			while (end >= pos && end != npos)	
			{
				_str[end + n] = _str[end];
				--end;
			}

			for (size_t i = 0; i < n; i++)
			{
				_str[pos + i] = c;
			}

			_size += n;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos < _size);

			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			for (size_t i = 0; i < len; i++)
			{
				_str[pos + i] = str[i];
			}

			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos <= _size);

			if (len == npos || len + pos > _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				for (size_t i = pos; i < _size; i++)
				{
					_str[i] = _str[pos + len + i];
				}
				_size -= len;
			}
		}

		size_t find(char c, size_t pos = 0)
		{
			assert(pos < _size);

			while (pos < _size)
			{
				if (_str[pos] == c)
				{
					return pos;
				}
				++pos;
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);

			const char* tmp = strstr(_str + pos, str);
			if (tmp)
			{
				return tmp - _str;
			}
			else
			{
				return npos;
			}
		}

		// 需要深拷贝配合使用
		//string substr(size_t pos = 0, size_t len = npos)


	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	public:
		const static size_t npos;
	};
	const size_t string::npos = -1;
}