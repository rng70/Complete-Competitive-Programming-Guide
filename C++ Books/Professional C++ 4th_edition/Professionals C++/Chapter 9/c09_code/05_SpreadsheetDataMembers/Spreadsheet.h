#pragma once

#include <cstddef>
#include "SpreadsheetCell.h"

class SpreadsheetApplication; // forward declaration

class Spreadsheet
{
public:
	Spreadsheet(size_t inWidth, size_t inHeight,
		const SpreadsheetApplication& theApp);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();
	Spreadsheet& operator=(const Spreadsheet& rhs);

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getId() const;

	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

	static const size_t kMaxHeight = 100;
	static const size_t kMaxWidth = 100;

private:
	bool inRange(size_t val, size_t upper) const;

	size_t mWidth, mHeight;
	size_t mId;
	SpreadsheetCell** mCells;

	const SpreadsheetApplication& mTheApp;

	static size_t sCounter;
};
