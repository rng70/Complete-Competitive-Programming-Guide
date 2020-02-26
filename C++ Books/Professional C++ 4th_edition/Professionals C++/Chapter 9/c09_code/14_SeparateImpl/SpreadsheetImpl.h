#pragma once

#include <cstddef>
#include "SpreadsheetCell.h"

class SpreadsheetApplication; // forward declaration

class SpreadsheetImpl
{
public:
	SpreadsheetImpl(const SpreadsheetApplication& theApp,
		size_t inWidth, size_t inHeight);
	SpreadsheetImpl(const SpreadsheetImpl& src);
	~SpreadsheetImpl();
	SpreadsheetImpl& operator=(const SpreadsheetImpl& rhs);

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getId() const;

	friend void swap(SpreadsheetImpl& first, SpreadsheetImpl& second) noexcept;

private:
	bool inRange(size_t val, size_t upper) const;

	size_t mWidth, mHeight;
	size_t mId;
	SpreadsheetCell** mCells;

	const SpreadsheetApplication& mTheApp;

	static size_t sCounter;
};
