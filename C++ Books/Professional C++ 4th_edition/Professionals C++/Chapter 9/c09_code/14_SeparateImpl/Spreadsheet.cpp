#include "Spreadsheet.h"
#include "SpreadsheetImpl.h"

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& inCell)
{
	mImpl->setCellAt(x, y, inCell);
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	return mImpl->getCellAt(x, y);
}

size_t Spreadsheet::getId() const
{
	return mImpl->getId();
}

Spreadsheet::Spreadsheet(const SpreadsheetApplication &theApp, size_t inWidth, size_t inHeight)
{
	mImpl = std::make_shared<SpreadsheetImpl>(theApp, inWidth, inHeight);
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
{
	mImpl = std::make_shared<SpreadsheetImpl>(*src.mImpl);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	*mImpl = *rhs.mImpl;
	return *this;
}
