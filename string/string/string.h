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
			// pos����Ϊ0 --> ��Ϊend����Ϊsize_t --> û�и���
			// ��end--��-1ʱ����Ϊsize_tû�и��������Ϊ���������ֵ��Ĭ���ַ�����������ô��
			// ���Կ������������������������
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

		// ��Ҫ������ʹ��
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