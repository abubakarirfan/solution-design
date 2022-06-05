#include <iostream>

#include "Combination.h"

using namespace std;

Combination::Combination(size_t aN, size_t aK) : fN(aN), fK(aK) {}


size_t Combination::getN() const
{
	return fN;
}

size_t Combination::getK() const
{
	return fK;
}

unsigned long long Combination::operator()() const
{
	unsigned long long lResult = 1;

	for (unsigned long long n = 1; n <= fK; n++)
	{
		lResult = (lResult * (fN - (n - 1))) / n;
	}

	return lResult;
}