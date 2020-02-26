#include "SpreadsheetImpl.h"
#include "Spreadsheet.h"
#include <stdexcept>
#include <utility>

size_t SpreadsheetImpl::sCounter;

SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetApplication& theApp,
	size_t inWidth, size_t inHeight)
	: mWidth(inWidth < Spreadsheet::kMaxWidth ? inWidth : Spreadsheet::kMaxWidth)
	, mHeight(inHeight < Spreadsheet::kMaxHeight ? inHeight : Spreadsheet::kMaxHeight)
	, mTheApp(theApp)
{
	mId = sCounter++;
	mCells = new SpreadsheetCell*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

SpreadsheetImpl::~SpreadsheetImpl()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetImpl& src)
	: SpreadsheetImpl(src.mTheApp, src.mWidth, src.mHeight)
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

bool SpreadsheetImpl::inRange(size_t val, size_t upper) const
{
	return val < upper;
}

void SpreadsheetImpl::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}

	mCells[x][y] = cell;
}

SpreadsheetCell& SpreadsheetImpl::getCellAt(size_t x, size_t y)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}
	return mCells[x][y];
}

void swap(SpreadsheetImpl& first, SpreadsheetImpl& second) noexcept
{
	using std::swap;

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}

SpreadsheetImpl& SpreadsheetImpl::operator=(const SpreadsheetImpl& rhs)
{
	// check for self-assignment
	if (this == &rhs) {
		return *this;
	}

	// Copy-and-swap idiom
	SpreadsheetImpl temp(rhs); // Do all the work in a temporary instance
	swap(*this, temp); // Commit the work with only non-throwing operations
	return *this;
}

size_t SpreadsheetImpl::getId() const
{
	return mId;
}
