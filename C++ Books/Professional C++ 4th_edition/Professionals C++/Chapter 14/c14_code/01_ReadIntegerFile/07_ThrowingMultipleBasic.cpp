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
		throw runtime_error("Unable to open the file.");
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
		throw runtime_error("Error reading the file.");
	}

	return integers;
}

int main()
{
	const string fileName = "IntegerFile.txt";
	vector<int> myInts;

	try {
		myInts = readIntegerFile(fileName);
	} catch (const exception& e) {
		cerr << e.what() << endl;
		return 1;
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}
