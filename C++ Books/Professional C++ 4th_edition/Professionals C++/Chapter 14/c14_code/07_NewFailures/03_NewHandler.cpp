#include <cstddef>
#include <new>
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

class PleaseTerminateMe : public bad_alloc { };

void myNewHandler()
{
	cerr << "Unable to allocate memory." << endl;
	throw PleaseTerminateMe();
}

int main()
{
	try {
		// Set the new new_handler and save the old.
		new_handler oldHandler = set_new_handler(myNewHandler);

		// Generate allocation error
		size_t numInts = numeric_limits<long long>::max();
		int* ptr = new int[numInts];

		// reset the old new_handler
		set_new_handler(oldHandler);
	} catch (const PleaseTerminateMe&) {
		cerr << __FILE__ << "(" << __LINE__
			<< "): Terminating program." << endl;
		return 1;
	}
	return 0;
}
