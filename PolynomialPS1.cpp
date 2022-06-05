#include <iostream>
#include <math.h>
#include "Polynomial.h"

using namespace std;


double Polynomial::operator()(double aX) const
{
    double Result = 0;

    for (size_t i = 0; i <= fDegree; i++)
    {
        Result += fCoeffs[i] * pow(aX, i);
    }

    return Result;
}

Polynomial Polynomial::getDerivative() const
{
    Polynomial lPolynomial;

    if (fDegree > 0)
    {
        for (int i = static_cast<int>(fDegree); i > 0; i--)
        {
            lPolynomial.fCoeffs[i - 1] = fCoeffs[i] * (i);
        }
        if (fDegree - 1 >= 0)
        {
            if (fDegree - 1 <= MAX_POLYNOMIAL)
            {
                lPolynomial.fDegree = fDegree - 1;
            }
            else
            {
                lPolynomial.fDegree = MAX_POLYNOMIAL;
            }
        }
        else
        {
            lPolynomial.fDegree = 0;
        }
        return lPolynomial;
    }
    else
    {
        return lPolynomial;
    }
}


Polynomial Polynomial::getIndefiniteIntegral() const
{
    Polynomial lPolynomial;
    lPolynomial.fDegree = fDegree + 1;

    for (size_t i = 1; i <= lPolynomial.fDegree; i++)
    {
        lPolynomial.fCoeffs[i] = fCoeffs[i - 1] / i;
    }

    return lPolynomial;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const
{
    return getIndefiniteIntegral()(aXHigh) - getIndefiniteIntegral()(aXLow);
}