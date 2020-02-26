#include "Spreadsheet.h"
#include "SpreadsheetCell.h"

int main()
{
	Spreadsheet s1(2, 2);

	SpreadsheetCell cell(1.2);
	s1.setCellAt(0, 0, cell);

	return 0;
}
