#pragma once

#include "SpreadsheetCell.h"
#include <memory>

// forward declarations
class SpreadsheetImpl;
class SpreadsheetApplication;

class Spreadsheet
{
public:
	Spreadsheet(const SpreadsheetApplication& theApp,
		size_t inWidth = kMaxWidth, size_t inHeight = kMaxHeight);
	Spreadsheet(const Spreadsheet& src);

	Spreadsheet& operator=(const Spreadsheet& rhs);
	
	void setCellAt(size_t x, size_t y, const SpreadsheetCell& inCell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);
	
	size_t getId() const;

	static const size_t kMaxHeight = 100;
	static const size_t kMaxWidth = 100;

private:
	std::shared_ptr<SpreadsheetImpl> mImpl;
};
