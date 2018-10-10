#pragma once

#include "stdafx.h"

template <typename T>
class CMyVector
{
private:
	T * aArray;
	int nSize;
public:
	CMyVector()
	{
		this->nSize = 0;
		this->aArray = new T[this->nSize];
	}

	void push_back(T Data)
	{
		T *Result = new T[++this->nSize];

		for (int nIndex = 0; nIndex < this->nSize; nIndex++)
		{
			if (nIndex != this->nSize - 1)
			{
				Result[nIndex] = this->aArray[nIndex];
			}
			else
			{
				Result[nIndex] = Data;
				break;
			}
		}
		delete[] this->aArray;
		this->aArray = Result;
	}

	T pop()
	{
		return this->popIndex(this->nSize - 1);
	}

	void clear()
	{
		if (this->aArray != NULL)
		{
			ZeroMemory(this->aArray, this->nSize);
		}
		this->nSize = 0;
		this->aArray = new T[this->nSize];
	}

	T operator [](int nIndex)
	{
		return this->aArray[nIndex];
	}

	int size()
	{
		return this->nSize;
	}

	void pushIndex(T data, int index)
	{
		int oldSize = this->nSize;

		if (this->nSize >= index)
		{
			this->nSize = ++this->nSize;
		}
		else
		{
			this->nSize = this->nSize + (index - this->nSize);
		}

		T *_result = new T[this->nSize];

		int arrIndex = 0;

		for (int index2 = 0; index2 < this->nSize; index2++)
		{
			if (index2 == index)
			{
				_result[index2] = data;
				continue;
			}

			if (arrIndex != oldSize)
			{
				_result[index2] = this->aArray[arrIndex++];
			}
		}
		delete[] this->aArray;
		this->aArray = _result;
	}

	T popIndex(int index)
	{
		T *_result = new T[--this->nSize];

		T resItem;

		int resIndex = 0;

		for (int index2 = 0; index2 < this->nSize + 1; index2++)
		{
			T item = this->aArray[index2];

			if (index == index2)
			{
				resItem = item;
				continue;
			}
			_result[resIndex++] = this->aArray[index2];
		}
		delete[] this->aArray;
		this->aArray = _result;
		return resItem;
	}
};
