#pragma once
#include "Array.h"
#include <cassert>

template<class T>
class OrderedArray : public Array<T>
{
public:
	OrderedArray(int size, int growBy = 1) : Array<T>(size, growBy) {}
	void push(T val)
	{
		assert(this->m_array != nullptr);
		if (this->search(val) != -1 && this->m_duplicateData)
		{
			std::cout << std::endl << "Duplicate value found" << std::endl;
			return;
		}
		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}
		int i, k;
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] > val)
			{
				break;
			}
		}

		for (k = this->m_numElements; k > i; k--)
		{
			this->m_array[k] = this->m_array[k - 1];
		}

		this->m_array[i] = val;
		this->m_numElements++;
	}

	int search(T val)
	{
		assert(this->m_array != nullptr);
		int lowerBound = 0;
		int upperBound = this->m_numElements - 1;
		int current = 0;



		while (1)
		{
			current = (lowerBound + upperBound) >> 1;
			if (this->m_array[current] == val)
			{
				return current;
			}
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				if (this->m_array[current] < val)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}

		return -1;
	}
};