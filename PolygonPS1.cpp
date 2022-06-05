#include "Polygon.h"

#include <stdexcept>

using namespace std;


float Polygon::getSignedArea() const
{
	float result = 0.0f;

	for (size_t i = 0; i < fNumberOfVertices - 1; i++)
	{
		result += fVertices[i].cross(fVertices[i+1]);
	}

	result += fVertices[fNumberOfVertices - 1].cross(fVertices[0]);

	float area = result / 2;

	return area;
}