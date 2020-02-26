#include <future>

using namespace std;

int main()
{
	promise<void> thread1_started, thread2_started;

	promise<void> signal_promise;
	shared_future<void> signal_future(signal_promise.get_future());

	auto f1 = [&thread1_started, signal_future] {
		thread1_started.set_value();
		// Wait until signal is raised.
		signal_future.wait();
		// ...
	};

	auto f2 = [&thread2_started, signal_future] {
		thread2_started.set_value();
		// Wait until signal is raised.
		signal_future.wait();
		// ...
	};

	// Launch two threads.
	auto res1 = async(launch::async, f1);
	auto res2 = async(launch::async, f2);

	// Wait until both threads have started.
	thread1_started.get_future().wait();
	thread2_started.get_future().wait();

	// Both threads are now waiting for the signal.
	// Raise the signal to wake both of them up.
	signal_promise.set_value();
}