#pragma once

#include <cstddef>
#include "Element.h"

class Matrix
{
public:
	Matrix(size_t width, size_t height);
	virtual ~Matrix();

private:
	size_t mWidth;
	size_t mHeight;
	Element** mMatrix;
};