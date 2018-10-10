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

	~CMyVector()
	{
		if (this->aArray != NULL)
		{
			ZeroMemory(this->aArray, this->nSize);
		}
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

	void pushIndex(T data, int nIndex)
	{
		int nOldSize = this->nSize;

		if (this->nSize >= nIndex)
		{
			this->nSize = ++this->nSize;
		}
		else
		{
			this->nSize = this->nSize + (nIndex - this->nSize);
		}

		T *pResult = new T[this->nSize];

		int nArrayIndex = 0;

		for (int nResultArrayIndex = 0; nResultArrayIndex < this->nSize; nResultArrayIndex++)
		{
			if (nResultArrayIndex == nIndex)
			{
				pResult[nResultArrayIndex] = data;
				continue;
			}

			if (nArrayIndex != nOldSize)
			{
				pResult[nResultArrayIndex] = this->aArray[nArrayIndex++];
			}
		}
		delete[] this->aArray;
		this->aArray = pResult;
	}

	T popIndex(int nIndex)
	{
		T *pResult = new T[--this->nSize];

		T resItem;

		int nResIndex = 0;

		for (int nResultArrayIndex = 0; nResultArrayIndex < this->nSize + 1; nResultArrayIndex++)
		{
			T item = this->aArray[nResultArrayIndex];

			if (nIndex == nResultArrayIndex)
			{
				resItem = item;
				continue;
			}
			pResult[nResIndex++] = this->aArray[nResultArrayIndex];
		}
		delete[] this->aArray;
		this->aArray = pResult;
		return resItem;
	}
};
