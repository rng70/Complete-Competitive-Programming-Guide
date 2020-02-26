#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>
#include <sstream>
#include <cstddef>

using namespace std;

class FileError : public exception
{
public:
	FileError(string_view fileIn) : mFile(fileIn) {}
	virtual const char* what() const noexcept override { return mMsg.c_str(); }
	string_view getFileName() const { return mFile; }

protected:
	void setMessage(string_view message) { mMsg = message; }

private:
	string mFile, mMsg;
};

class FileOpenError : public FileError
{
public:
	FileOpenError(string_view fileNameIn)
		: FileError(fileNameIn)
	{
		setMessage("Unable to open "s + fileNameIn.data());
	}
};

class FileReadError : public FileError
{
public:
	FileReadError(string_view fileNameIn, size_t lineNumIn)
		: FileError(fileNameIn), mLineNum(lineNumIn)
	{
		ostringstream ostr;
		ostr << "Error reading " << fileNameIn << " at line " << lineNumIn;
		setMessage(ostr.str());
	}

	size_t getLineNum() const { return mLineNum; }

private:
	size_t mLineNum;
};


vector<int> readIntegerFile(string_view fileName)
{
	ifstream istr(fileName.data());
	if (istr.fail()) {
		// We failed to open the file: throw an exception
		throw FileOpenError(fileName);
	}

	vector<int> integers;
	size_t lineNumber = 0;
	while (!istr.eof()) {
		// Read one line from the file
		string line;
		getline(istr, line);
		++lineNumber;

		// Create a string stream out of the line
		istringstream lineStream(line);

		// Read the integers one-by-one and add them to a vector
		int temp;
		while (lineStream >> temp) {
			integers.push_back(temp);
		}

		if (!lineStream.eof()) {
			// We did not reach the end of the string stream.
			// This means that some error occurred while reading this line.
			// Throw an exception.
			throw FileReadError(fileName, lineNumber);
		}
	}

	return integers;
}

int main()
{
	const string fileName = "IntegerFile.txt";
	vector<int> myInts;

	try {
		myInts = readIntegerFile(fileName);
	} catch (const FileError& e) {
		cerr << e.what() << endl;
		return 1;
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}
