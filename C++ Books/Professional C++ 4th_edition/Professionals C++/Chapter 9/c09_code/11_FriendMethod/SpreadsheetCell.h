#pragma once

#include <string>
#include <string_view>
#include "Spreadsheet.h"

class SpreadsheetCell
{
public:
	friend void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);

	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	SpreadsheetCell(std::string_view initialValue);

	void setValue(double inValue);
	double getValue() const;

	void setString(std::string_view inString);
	std::string getString() const;

private:
	std::string doubleToString(double inValue) const;
	double stringToDouble(std::string_view inString) const;

	double mValue = 0;
};

