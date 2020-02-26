#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>

using namespace std;

vector<int> readIntegerFile(string_view fileName)
{
	ifstream istr(fileName.data());
	if (istr.fail()) {
		// We failed to open the file: throw an exception
		const string error = "Unable to open file "s + fileName.data();
		throw invalid_argument(error);
	}

	// Read the integers one-by-one and add them to a vector
	vector<int> integers;
	int temp;
	while (istr >> temp) {
		integers.push_back(temp);
	}

	if (!istr.eof()) {
		// We did not reach the end-of-file.
		// This means that some error occurred while reading the file.
		// Throw an exception.
		const string error = "Unable to read file "s + fileName.data();
		throw runtime_error(error);
	}

	return integers;
}

int main()
{
	const string fileName = "IntegerFile.txt";
	vector<int> myInts;

	try {
		myInts = readIntegerFile(fileName);
	} catch (const exception& e) { // BUG: catching base class first!
		cerr << e.what() << endl;
		return 1;
	} catch (const invalid_argument& /* e */) {
		// Take some special action for invalid filenames.
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}
