#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
	, mMatrix(nullptr)
{
	mMatrix = new Element*[width];
	size_t i = 0;
	try {
		for (i = 0; i < width; ++i)
			mMatrix[i] = new Element[height];
	} catch (...) {
		cout << "Exception caught in constructor, cleaning up..." << endl;

		// Clean up any memory we already allocated, because the destructor
		// will never be called. The upper bound of the for loop is the
		// index of the last element in the mMatrix array that we tried
		// to allocate (the one that failed). All indices before that
		// one store pointers to allocated memory that must be freed.
		for (size_t j = 0; j < i; j++) {
			delete[] mMatrix[j];
		}
		delete[] mMatrix;
		mMatrix = nullptr;
		// Translate any exception to bad_alloc.
		throw bad_alloc();
	}
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < mWidth; ++i)
		delete[] mMatrix[i];
	delete[] mMatrix;
	mMatrix = nullptr;
}
