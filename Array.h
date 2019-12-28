#include<iostream>
using namespace std;
template<typename T>
class Array
{
private:
	T * data;
	int capacity;
	int isValidIndex(int index) const
	{
		return index >=0 && index < capacity;
	}
public:
	~Array()
	{
		if (data)
		{
			delete[] data;
			
		}
		data = 0;
		capacity = 0;

	}

	T & operator [] (int i)
	{
		if (isValidIndex(i))
		{
			return data[i];
		}
		exit(0);

	}

	Array <T> & operator =(Array<T> & ref)
	{
		if (this->data = ref.data)
		{
			return;
		}
		if (ref.data)
		{
			this->~Array();
			capacity = ref.capacity;
			data = new T[capacity];
			for (int i = 0; i < capacity; i = i + 1)
			{
				data[i] = ref.data[i];
			}
			return *this;
		}
		capacity = 0;
		data = 0;
		return *this;
	}


	Array(const Array<T> & ref)
	{
		if (ref.data == 0)
		{
			return;
		}

		capacity = ref.capacity;
		data = new T[capacity];
		for (int i = 0; i < capacity; i = i + 1)
		{
			data[i] = ref.data[i];
		}


	}

	Array()
	{
	
		data = 0;
		capacity = 0;
	}


	const T & operator [](int i) const
	{
		if (isValidIndex(i))
			return data[i];
		exit(0);
	}

	int getCapacity()
	{
		return capacity;
	}

	void reSize(int newCap)
	{
		
		if (newCap <= 0)
		{
			this->~Array();
			return;
		}
		
		T * ptr = new T[newCap];
		int size = newCap < capacity ? newCap : capacity;
		for (int i = 0; i < size; i = i + 1)
		{
			ptr[i] = data[i];
		}

		capacity = newCap;
		data = ptr;
	}


	Array(initializer_list<T> list)
	{
		capacity = list.size();
		if (capacity == 0)
		{
			data = 0;
			return;
		}

		data = new T[capacity];
		int j = 0;
		for (auto i : list)
		{
			data[j] = i;
			j = j + 1;
		}


	}
};