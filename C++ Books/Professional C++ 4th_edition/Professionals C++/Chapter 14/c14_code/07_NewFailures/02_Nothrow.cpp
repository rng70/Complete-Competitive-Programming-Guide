#include <cstddef>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	size_t numInts = numeric_limits<long long>::max();
	cout << "Trying to allocate memory for " << numInts << " integers." << endl;

	int* ptr = new(nothrow) int[numInts];
	if (ptr == nullptr) {
		cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory!" << endl;
		// Handle memory allocation failure
		return 1;
	}
	// Proceed with function that assumes memory has been allocated

	return 0;
}
