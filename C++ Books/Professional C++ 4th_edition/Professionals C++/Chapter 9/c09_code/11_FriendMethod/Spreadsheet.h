#pragma once

#include <cstddef>

class SpreadsheetCell;	// Forward declaration

class Spreadsheet
{
public:
	Spreadsheet(size_t inWidth, size_t inHeight);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs);

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

private:
	bool inRange(size_t val, size_t upper) const;

	size_t mWidth, mHeight;
	SpreadsheetCell** mCells;
};
