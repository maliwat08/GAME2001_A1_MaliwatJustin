#pragma once
#include "Array.h"
#include <cassert>

template<class T>
class UnorderedArray : public Array<T>
{
public:
	UnorderedArray(int size, int growBy = 1) : Array<T>(size, growBy) {}
	void push(T val)
	{
		assert(this->m_array != nullptr);
		if (this->search(val) != -1 && this->m_duplicateData)
		{
			std::cout << std::endl << "found a duplicate" << std::endl;
			return;
		}
		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}
		this->m_array[this->m_numElements] = val;
		this->m_numElements++;
	}
	int search(T val)
	{
		assert(this->m_array != nullptr);
		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == val)
			{
				return i;
			}
		}
		return -1;
	}
};