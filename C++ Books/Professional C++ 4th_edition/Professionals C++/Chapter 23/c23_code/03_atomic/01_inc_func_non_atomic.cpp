#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <chrono>

using namespace std;

void func(int& counter)
{
	for (int i = 0; i < 100; ++i) {
		++counter;
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}

int main()
{
	int counter = 0;
	vector<thread> threads;

	for (int i = 0; i < 10; ++i) {
		threads.push_back(thread{ func, ref(counter) });
	}

	for (auto& t : threads) {
		t.join();
	}

	cout << "Result = " << counter << endl;

	return 0;
}
