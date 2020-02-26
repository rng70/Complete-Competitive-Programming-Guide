#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

using namespace std;

void initializeSharedResources()
{
	// ... Initialize shared resources that will be used by multiple threads.

	cout << "Shared resources initialized." << endl;
}

atomic<bool> initialized(false);
mutex mut;

void func()
{
	if (!initialized) {
		unique_lock<mutex> lock(mut);
		if (!initialized) {
			initializeSharedResources();
			initialized = true;
		}
	}
	cout << "OK" << endl;
}

int main()
{
	vector<thread> threads;

	for (int i = 0; i < 5; ++i) {
		threads.push_back(thread{ func });
	}

	for (auto& t : threads) {
		t.join();
	}

	return 0;
}
