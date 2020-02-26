#include <iostream>
#include <future>
#include <exception>
#include <stdexcept>

using namespace std;

int calculate()
{
	throw runtime_error("Exception thrown from a thread.");
}

int main()
{
	// Use launch::async policy to force a new thread.
	auto fut = async(launch::async, calculate);

	// Do some more work...

	// Get result
	try {
		int res = fut.get();
		cout << res << endl;
	} catch (const exception& ex) {
		cout << "Caught exception: " << ex.what() << endl;
	}

	return 0;
}
