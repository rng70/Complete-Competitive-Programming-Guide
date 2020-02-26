#include "Spreadsheet.h"
#include <stdexcept>
#include <utility>

using namespace std;

size_t Spreadsheet::sCounter;

Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp,
	size_t inWidth, size_t inHeight)
	: mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth)
	, mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight)
	, mTheApp(theApp)
{
	mId = sCounter++;
	mCells = new SpreadsheetCell*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

Spreadsheet::~Spreadsheet()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet(src.mTheApp, src.mWidth, src.mHeight)
{
	// The ctor-initializer of this constructor delegates first to the
	// non-copy constructor to allocate the proper amount of memory.

	// The next step is to copy the data.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

bool Spreadsheet::inRange(size_t val, size_t upper) const
{
	return val < upper;
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}

	mCells[x][y] = cell;
}

/*
Spreadsheet::SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}
	return mCells[x][y];
}
*/

SCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}
	return mCells[x][y];
}

void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	using std::swap;

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	// check for self-assignment
	if (this == &rhs) {
		return *this;
	}

	// Copy-and-swap idiom
	Spreadsheet temp(rhs); // Do all the work in a temporary instance
	swap(*this, temp); // Commit the work with only non-throwing operations
	return *this;
}

size_t Spreadsheet::getId() const
{
	return mId;
}





SCell::SpreadsheetCell(double initialValue)
	: mValue(initialValue)
{
}

SCell::SpreadsheetCell(string_view initialValue)
	: mValue(stringToDouble(initialValue))
{
}

void SCell::set(double inValue)
{
	mValue = inValue;
}

void SCell::set(string_view inString)
{
	mValue = stringToDouble(inString);
}

string SCell::doubleToString(double inValue)
{
	return to_string(inValue);
}

double SCell::stringToDouble(string_view inString)
{
	return strtod(inString.data(), nullptr);
}

/*
Spreadsheet::SpreadsheetCell::SpreadsheetCell(double initialValue)
	: mValue(initialValue)
{
}

Spreadsheet::SpreadsheetCell::SpreadsheetCell(string_view initialValue)
	: mValue(stringToDouble(initialValue))
{
}

void Spreadsheet::SpreadsheetCell::set(double inValue)
{
	mValue = inValue;
}

void Spreadsheet::SpreadsheetCell::set(string_view inString)
{
	mValue = stringToDouble(inString);
}

string Spreadsheet::SpreadsheetCell::doubleToString(double inValue)
{
	return to_string(inValue);
}

double Spreadsheet::SpreadsheetCell::stringToDouble(string_view inString)
{
	return strtod(inString.data(), nullptr);
}
*/