#pragma once

#include "stdafx.h"
#include "CMyVector.h"

class CAddingNumbers
{
private:
	CMyVector <float> aNumbers;
	float fSum;

public:
	CAddingNumbers();
	~CAddingNumbers();

	float getSum();
	CMyVector <float> getNumbers();

	void readNumbers();
	void addNumbers();
	bool isDigit(char chCharacter);
};

