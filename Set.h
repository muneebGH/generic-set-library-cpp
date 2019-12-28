#include"Array.h"
template<typename T>
class Set
{
private:
	Array<T> arr;
	int noOfElements;
public:
	Set(int cap = 5)
	{
		arr.reSize(cap);
		noOfElements = 0;
	}

	~Set()
	{
		arr.~Array();
		noOfElements = 0;
	}

	void insert(T element)
	{
		if (noOfElements >= arr.getCapacity())
		{
			arr.reSize(arr.getCapacity() + 1);

		}

		if (isMember(element)!=-1)
		{
			return;
		}
		arr[noOfElements] = element;
		noOfElements = noOfElements + 1;
	}


	int getCardenality()
	{
		return noOfElements;
	}

	int isMember(T val)const
	{
		for(int i=0;i<noOfElements;i=i+1)
		{	
			if (arr[i] == val)
			{
				return i;
			}
		}

		return -1;
	}


	void print()
	{
		for (int i = 0; i < noOfElements; i = i + 1)
		{
			cout << arr[i];
		}


	}
	
	void reSize(int newCap)
	{
		arr.reSize(newCap);
		noOfElements = noOfElements > newCap ? newCap : noOfElements;

	}


	Set(const Set<T> & ref):arr(ref.arr)
	{
		noOfElements = ref.noOfElements;
	}

	void remove(T val)
	{
		int index = isMember(val);
		if (index == -1)
		{
			return;
		}

		for (int i = index; i < noOfElements-1; i = i + 1)
		{
			arr[i] = arr[i + 1];
		}

		noOfElements = noOfElements - 1;


	}

	Set<T> calcUnion(const Set<T> & ref)const
	{
		
		int size = ref.noOfElements + noOfElements;
		Set unionSet(size);
		for (int i = 0; i < noOfElements; i = i + 1)
		{
			unionSet.insert(arr[i]);
		}

		for (int i = 0; i < ref.noOfElements; i = i + 1)
		{
			if (unionSet.ismember(ref.arr[i]) != -1)
			{
				unionSet.insert(ref.arr[i]);
			}
		}

		return unionSet;
	}


	Set<T> calcIntersection(const Set<T> & ref)
	{
		Set<T> inter;
		for (int i = 0; i < ref.noOfElements; i = i + 1)
		{
			for (int i = 0; i < noOfElements; i = i + 1)
			{
				if (ref.arr[i] == arr[i])
				{
					inter.insert(arr[i]);
					break;
				}
			}
		}

		return inter;
	}


};

