#include <iostream>
#include <math.h>
#include "Combination.h"
#include "BernsteinBasisPolynomial.h"

using namespace std;

BernsteinBasisPolynomial::BernsteinBasisPolynomial(unsigned int aV, unsigned int aN) : fFactor(aN, aV) {}

double BernsteinBasisPolynomial::operator()(double aX) const
{
	return (fFactor() * pow(aX, fFactor.getK()) * pow((1 - aX), (fFactor.getN() - fFactor.getK())));
}