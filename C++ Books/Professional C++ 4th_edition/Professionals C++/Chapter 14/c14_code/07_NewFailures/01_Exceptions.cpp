#include <cstddef>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	int* ptr = nullptr;
	size_t numInts = numeric_limits<long long>::max();
	cout << "Trying to allocate memory for " << numInts << " integers." << endl;

	try {
		ptr = new int[numInts];
	} catch (const bad_alloc& e) {
		cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory: " << e.what() << endl;
		// Handle memory allocation failure
		return 1;
	}
	// Proceed with function that assumes memory has been allocated

	return 0;
}
