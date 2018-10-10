#include "CAddingNumbers.h"

CAddingNumbers:: CAddingNumbers()
{
	this->aNumbers.clear();
	this->fSum = 0;
}

CAddingNumbers:: ~CAddingNumbers()
{
	this->aNumbers.clear();
}

float CAddingNumbers:: getSum()
{
	return this->fSum;
}

CMyVector <float> CAddingNumbers:: getNumbers()
{
	return this->aNumbers;
}

void CAddingNumbers:: readNumbers()
{
	std::string sInputNumbers;
	std::getline(std::cin, sInputNumbers);
	std::string sNumber;
	for (unsigned int nCharacterIndex = 0; nCharacterIndex < sInputNumbers.size(); nCharacterIndex++)
	{
		while (isDigit(sInputNumbers[nCharacterIndex]) || sInputNumbers[nCharacterIndex] == '.')
		{
			sNumber.push_back(sInputNumbers[nCharacterIndex]);
			nCharacterIndex++;
		}
		this->aNumbers.push_back(stof(sNumber));
		sNumber.clear();
	}
}

void CAddingNumbers:: addNumbers()
{
	for (unsigned int nNumberIndex = 0; nNumberIndex < aNumbers.size(); nNumberIndex++)
	{
		this->fSum += aNumbers[nNumberIndex];
	}
}

bool CAddingNumbers:: isDigit(char chCharacter)
{
	if (chCharacter >= '0' && chCharacter <= '9') return true;
	else return false;
}